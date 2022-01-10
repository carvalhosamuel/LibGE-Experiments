#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>

#include <ga/ga.h>
#include <GE/ge.h>

// Include our custom header so we can access the _evaluated flag of a genome
#include "../include/GAGenomeMulti.h"

// Set this flag to evaluate each genome only once
// Remove if you wish for the genome to be evaluated every time
#define SINGLE_EVAL

using namespace std;

// GE mapper, declared in main.cpp
extern GEGrammarSI mapper;
extern std::string simulator;

// Function Prototypes
void createIndividual(GAGenome &g, unsigned long id);
void createTestbench(GAPopulation &p);

// Simulator Prototypes
void evaluateTestbenchIcarus();
void evaluateTestbenchVivado(GAPopulation &p);
void evaluateTestbenchModelsim(GAPopulation &p);

// Verilog Testbench Prototypes
int getPortCount();                // Returns number of ports on an individual
string getPortNameModule();            // Returns the name of the ports of an individual
string getPortNameTestbench(int id);   // Returns the name of the ports of an individual to connect them to the testbench
string getTestbenchVar();           // Returns the variables required to connect the DUT to the testbench
string getTestbenchVarConcat();              // Returns a concatenated string of all ports
string getTaskInputs();               // Returns a string that declares the task inputs
string assignTaskInputs();         // Returns a string that assigns the vector value to the testbench inputs
string initializePreviousStateRegisters(int id);

// Empty evaluator that increments neval and sets score to zero
//float emptyEvaluator(GAGenome&){/*cout << "RUN";*/return 0;};

// Custom initializer, not currently used.
void customInitializer(GAPopulation &p) {
  //cout << "Running my custom initializer!" << endl;

  // Create temporary directory to store generated files for this run
  char workname[] = "tmp/run.XXXXXX";
  string work_dir = mkdtemp(workname);
  cout << "Temporary directory for run created at: " << work_dir << endl;
  if(system(("rm -r " + work_dir).c_str()) == 0){
    cout << "Temporary directory for run removed at: " << work_dir << endl;
  }
  else
  {
    cerr << "Unable to remove temporary directory: " << work_dir << endl;
    cerr << "Execution aborted.\n";
    exit(1);
  }

  // Run the initializer function for each individual
  for (int i = 0; i < p.size(); i++){
    p.individual(i).initialize();
  }
}

// Custom evaluator. Here we generate all of the individuals in a given population
// and then include them in a testbench. We then feed the scores back into GALib
// so it can do its thing.
void customEvaluator(GAPopulation &p) {
  //cout << "Running my custom evaluator!" << endl;
  bool run_testbench = false;

  

  // Create all individuals in current generation required to run testbench  
  // Note: Need to add feature so that only non-evaluated individuals are included
  for (int id = 0; id < p.size(); id++){
#ifdef SINGLE_EVAL
    if(reinterpret_cast<GAGenomeMulti*>(&p.individual(id))->getEvaluated() == 0){
#endif
      createIndividual(p.individual(id), id);
      run_testbench = true;
#ifdef SINGLE_EVAL
    }
#endif
  }

  // If an individual needs to be evaluated, run the testbench and get a score
  if(run_testbench){
    // Create the testbench.sv file so that we can run the simulation
    createTestbench(p);

    // Evaluate the testbench.sv file so that we get scores
    // Uncomment to run the appropriate simulator
    if(simulator == "icarus"){
      evaluateTestbenchIcarus();
    }
    else if(simulator == "vivado"){
      evaluateTestbenchVivado(p);
    }
    else if(simulator == "modelsim"){
      evaluateTestbenchModelsim(p);
    }
    else{
      cerr << "Unsupported simulator: " << simulator << endl;
      cerr << "Execution aborted.\n";
      exit(1);
    }

    // This evaluates all individuals
    // Assign the fitness scores back to the individuals so GALib can perform
    // mutation and crossover
    ifstream results("tmp/results");
    string line;
    float value = 0;
    int id = 0;
    if(results.is_open())
    {
      while(results >> value)
      {
        if(!results.eof()){
#ifdef SINGLE_EVAL
          if(reinterpret_cast<GAGenomeMulti*>(&p.individual(id))->getEvaluated() == 0){
#endif
            // This part is a bit confusing. The only way we can check if an individual
            // has been evaluted is call nevals and check if it is non-zero. However, we
            // can't set this directly, and can't get the value of _evaluated in the GAGenome.
            // So as a workaround, we call an empty individual-based evaluator so that it
            // it increments nevals that we can then check it in the testbench evaluation.
            // This is not the clearest way to do this but it makes the code much easier to
            // write without having to change the GALib library.
            p.individual(id).score(value);
#ifdef SINGLE_EVAL
          }
#endif
          id++;
        }
      }
    }
    else{
      cerr << "Could not open tmp/results\n";
      cerr << "Execution aborted.\n";
      exit(1);
    }
    results.close();
  } 
}

// Work functions here

// Create an individual in tmp and assign a unique ID
// so we can include each one in the testbench
void createIndividual(GAGenome &g, unsigned long id){
  GEListGenome &genome = static_cast<GEListGenome&>(g);
  //Assign genotype to mapper
  mapper.setGenotype(genome);
  //Grab phenotype
  Phenotype const *phenotype=mapper.getPhenotype();
  if(phenotype->getValid())
  {
    // Create file handler
    FILE *file;

    //Create output file
    string filename = "tmp/individual_" + to_string(id) + ".sv";
    if(!(file=fopen(filename.c_str(),"w")))
    {
      cerr << "Could not open " + filename + "\n";
      cerr << "Execution aborted.\n";
      exit(1);
    }

    // Read port connections
    string ports = getPortNameModule();

    string start_module = "module individual_" + to_string(id) + ports + "\n";
    string end_module = "\nendmodule";

    // Write start buffer to file
    fprintf(file,"%s",start_module.c_str());
    // Write phenotype code to file
    fprintf(file,"%s",phenotype->getString().c_str());
    // Write end buffer to file
    fprintf(file,"%s",end_module.c_str());

    // Close the file
    fclose(file);
  }
  else 
  {
    // We have a mapping error. Needs to be handled. Exit for now
    cerr << "Error: Phenotype not valid.\n";
    cerr << "Execution aborted.\n";
    exit(1);
  }
}

// Create the testbench that instantiates the number of individuals
// in the population
void createTestbench(GAPopulation &p){
  // Use ofstream to write to testbench.sv
  ofstream file;
  string line;

  // Open the file to write
  file.open("tmp/testbench.sv");

  // Check that the file opened correctly. If not, then exit.
  if(!file.is_open())
  {
    cerr << "Could not open tmp/testbench.sv.\n";
    cerr << "Execution aborted.\n";
    exit(1);
  }

  // Read in the testbench template and replace the tags accordingly
  ifstream testbench_start("template/testbench.sv");
  if(testbench_start.is_open())
  {
    while(getline(testbench_start,line))
    {
      #define TAG_SIZE 3
      size_t tag_start = line.find("<<<");
      size_t tag_end = line.find(">>>");
      size_t tag_size = tag_end-tag_start-TAG_SIZE;
      // Iterate through the testbench looking for tags to replace
      if(tag_start != string::npos && tag_end != string::npos){
        // Replace tag found, replace accordingly
        //cout << "START: " << tag_start << " | END: " << tag_end << " | SIZE: " << tag_size << endl;
        string before_tag = line.substr(0, tag_start);
        string after_tag = line.substr(tag_end+TAG_SIZE, string::npos);
        string tag = line.substr(tag_start+TAG_SIZE, tag_size);
        //cout << "Tag found: " << tag << endl;

        // Print the section of the line before the tag to the output
        //cout << "Before Tag: " << before_tag << endl;
        file << before_tag;
        
        // Replace the tags with the correct strings
        if(tag == "include"){
          for (int id = 0; id < p.size(); id++){
#ifdef SINGLE_EVAL
            if(reinterpret_cast<GAGenomeMulti*>(&p.individual(id))->getEvaluated() == 0){
#endif
              string include = "\`include \"tmp/individual_" + to_string(id) + ".sv\"";
              file << include << endl;
#ifdef SINGLE_EVAL
            }
#endif
          }
        }
        else if(tag == "population_size") {
          file << to_string(p.size());
        }
        else if(tag == "test_count") {
          int line_count = 0;
          ifstream number_of_tests("template/test_vectors.tv");
          if(number_of_tests.is_open()){
            while(getline(number_of_tests,line))
            {
              if(!number_of_tests.eof()){
                line_count++;
              }
            }
          }
          else{
            cerr << "Could not open template/test_vectors.tv.\n";
            cerr << "Execution aborted.\n";
            exit(1);
          }
          number_of_tests.close();
          file << to_string(line_count);
        }
        else if(tag == "period") {
          // TODO: REPLACE
          file << "10";
        }
        else if(tag == "cycles_per_test") {
          // TODO: REPLACE
          file << "1";
        }
        else if(tag == "testbench_variables") {
          file << getTestbenchVar();
        }
        else if(tag == "port_count") {
          file << getPortCount();
        }
        else if(tag == "instantiate_individuals") {
          for (int id = 0; id < p.size(); id++){
#ifdef SINGLE_EVAL
            if(reinterpret_cast<GAGenomeMulti*>(&p.individual(id))->getEvaluated() == 0){
#endif
              string connections = getPortNameTestbench(id);
              string instantiate = "  individual_" + to_string(id) + " dut_" + to_string(id) + "(" + connections + ");\n";
              file << instantiate;
#ifdef SINGLE_EVAL
            }
#endif
          }
        }
        else if(tag == "task_inputs") {
          file << getTaskInputs();
        }
        else if(tag == "assign_inputs") {
          file << assignTaskInputs();
        }
        else if(tag == "testcase") {
          ifstream testcase("template/testcase.sv");
          if(testcase.is_open())
          {
            while(getline(testcase,line))
            {
              file << line << endl;
            }
            file << endl;
          }
          else{
            cerr << "Could not open template/testcase.sv.\n";
            cerr << "Execution aborted.\n";
            exit(1);
          }
          testcase.close();
        }
        else if(tag == "load_testbench_variables") {
          file << getTestbenchVarConcat();
        }
        else {
          cerr << "Could not find a replacement for the tag: " << tag << endl;
          cerr << "Execution aborted." << endl;
          exit(1);
        }

        // Print the section of the line after the tag to the output
        //cout << "After Tag: " << after_tag << endl;
        file << after_tag << endl;
      }
      else {
        // No tags found, just copy line to output file
        file << line << endl;
      }
    }
  }
  else{
    cerr << "Could not open template/testbench_start.sv.\n";
    cerr << "Execution aborted.\n";
    exit(1);
  }
  testbench_start.close();

  // Close the file
  file.close();
}

// Functions to evaluate the testbench using Icarus, Modelsim or Vivado

void evaluateTestbenchIcarus(){
  // Call the simulator - In this case Icarus Verilog
  system("echo 0 > tmp/results && iverilog -g2009 -o tmp/a.out tmp/testbench.sv && tmp/a.out | tail -n +2 > tmp/results");
}

void evaluateTestbenchVivado(GAPopulation &p){
  // Check which individuals need to be parsed
  string parse_individuals = "";
  for (int id = 0; id < p.size(); id++){
#ifdef SINGLE_EVAL
    if(reinterpret_cast<GAGenomeMulti*>(&p.individual(id))->getEvaluated() == 0){
#endif
      parse_individuals += "tmp/individual_" + to_string(id) + ".sv ";
#ifdef SINGLE_EVAL
    }
#endif
  }
  // Parse design files
  string parse_command = "xvlog -sv " + parse_individuals + " -nolog >/dev/null 2>&1 && xvlog -sv tmp/testbench.sv -nolog >/dev/null 2>&1";
  system(parse_command.c_str());

  // Elaborate and Generate a design snapshot
  system("xelab -debug typical testbench -s testbench_sim -nolog >/dev/null 2>&1");

  // Call the simulator | -nojournal flag works for calling vivado but not xsim.
  system("echo 0 > tmp/results && xsim testbench_sim -runall -nolog | sed '1,/run -all/d;/$finish/,$d' | tail -n +1 > tmp/results");

  // Clean up
  system("rm *.pb *.jou *.wdb && rm webtalk*");

  // Note - A small performance gain could be made here by not deleting the xsim.dir folder as Vivado needs to request a webtalk license every time a new folder is created.
  // We are deleting here to keep the root directory clean and the performance gain is minor
  system("rm -rf xsim.dir .Xil");
}

void evaluateTestbenchModelsim(GAPopulation &p){
  // Create work library
  system("vlib work");

  // Check which individuals need to be parsed
  string parse_individuals = "";
  for (int id = 0; id < p.size(); id++){
#ifdef SINGLE_EVAL
    if(reinterpret_cast<GAGenomeMulti*>(&p.individual(id))->getEvaluated() == 0){
#endif
      parse_individuals += "tmp/individual_" + to_string(id) + ".sv ";
#ifdef SINGLE_EVAL
    }
#endif
  }
  // Parse design files
  string parse_command = "vlog " + parse_individuals + " -quiet && vlog tmp/testbench.sv -quiet";
  system(parse_command.c_str());

  // Call the simulator - suppressing warning 3116 as it is due to absolute addressing, and is not important
  system("echo 0 > tmp/results && vsim testbench -c -do \"run -all; exit\" -quiet -nolog -suppress 3116 | sed '1,/# run -all/d;/$finish/,$d' | sed 's/^..//' | tail -n +1 > tmp/results");

  // Clean up work library
  system("vdel -all");
}

// The functions after this point are for generating the testbench.
// This needs to be tidied up but works for now.

int getPortCount(){
  int line_count = 0;
  string line;

  ifstream port_file("template/individual_ports.sv");
  if(port_file.is_open())
  {
    while(getline(port_file,line))
    {
      line_count++;
    }
  }
  else{
    cerr << "Could not open template/individual_ports.sv.\n";
    cerr << "Execution aborted.\n";
    exit(1);
  }
  port_file.close();

  return line_count;

}

string getPortNameTestbench(int id){
  //string result = "(";
  string result = "";
  string line;
  int var_count = 0;

  ifstream port_file("template/individual_ports.sv");
  if(port_file.is_open())
  {
    while(getline(port_file,line))
    {
      if(line.find("input") != string::npos || line.find("output") != string::npos){
        // Connections found
        if(var_count > 0){
          result += ", ";
        }

        // Get parameter name
        string param_name = "";
        std::size_t param_location = line.find_last_of(" ");
        if (param_location != std::string::npos){
          // Found start of parameter, lets get its name
          param_name = line.substr(param_location+1);
          //cout << param_name << "\n";
        }
        else{
          // Parameter not found, exit for now...
          cerr << "Error finding parameter name.\n";
          cerr << "Execution aborted.\n";
          exit(1);
        }

        if(line.find("input") != string::npos){
          result += "." + param_name + "(" + param_name + ")";
          var_count++;
        }
        else if(line.find("output") != string::npos){
          result += "." + param_name + "(" + param_name + "_current[" + to_string(id) + "]" + ")";
          var_count++;
        }
      }
      else {
        cerr << "Error parsing port module connections.\n";
        cerr << "Execution aborted.\n";
        exit(1);
      }
    }
  }
  else{
    cerr << "Could not open template/individual_ports.sv.\n";
    cerr << "Execution aborted.\n";
    exit(1);
  }
  port_file.close();

  //result += ");";
  return result;
}

string getPortNameModule(){
  string result = "(";
  string line;
  int var_count = 0;

  ifstream port_file("template/individual_ports.sv");
  if(port_file.is_open())
  {
    while(getline(port_file,line))
    {
      if(line.find("input") != string::npos || line.find("output") != string::npos){
        var_count++;
        // Connections found
        if(var_count > 1){
          result += ", ";
        }
        result += line;
      }
      else {
        cerr << "Error parsing port module connections.\n";
        cerr << "Execution aborted.\n";
        exit(1);
      }
    }
  }
  else{
    cerr << "Could not open template/individual_ports.sv.\n";
    cerr << "Execution aborted.\n";
    exit(1);
  }
  port_file.close();

  result += ");";
  return result;
}

string getTestbenchVar(){
  string result = "";
  string line;
  int var_count = 0;

  ifstream port_file("template/individual_ports.sv");
  if(port_file.is_open())
  {
    while(getline(port_file,line))
    {
      if(line.find("input") != string::npos || line.find("output") != string::npos){
        // Get parameter name
        string param_name = "";

        // Check if bus width is declared
        std::size_t bus_start = line.find("[");
        if (bus_start != std::string::npos){
          param_name = line.substr(bus_start);
        }
        else {
          std::size_t param_location = line.find_last_of(" ");
          if (param_location != std::string::npos){
            // Found start of parameter, lets get its name
            param_name = line.substr(param_location+1);
          }
          else{
            // Parameter not found, exit for now...
            cerr << "Error finding parameter name.\n";
            cerr << "Execution aborted.\n";
            exit(1);
          }
        }

        // If param name is equal to "clk" or "rst", we can ignore as it is already declared
        if(param_name == "clk" || param_name == "rst"){
          continue;
        }
        else {
          // reg drives an input, wire displays an output
          if(line.find("input") != string::npos){
            result += "\treg " + param_name + ";\n";
            var_count++;
          }
          else if(line.find("output wire") != string::npos){
            result += "\treg " + param_name + "_expected;\n";
            result += "\twire " + param_name + "_current[`POPULATION_SIZE];\n";
            var_count++;
          }
          else if(line.find("output reg") != string::npos){
            result += "\treg " + param_name + "_expected;\n";
            result += "\twire " + param_name + "_current[`POPULATION_SIZE];\n";
            var_count++;
          }

          // Add logic type support - disabled for now as impossible to tell
          // if a connection has state or not (ie reg or wire)

          /* else if(line.find("input logic") != string::npos){
            result += "\tlogic " + param_name + ";\n";
          }
          else if(line.find("output logic") != string::npos){
            result += "\tlogic " + param_name + "_expected;\n";
            result += "\tlogic " + param_name + "_current[`POPULATION_SIZE];\n";
          }*/
        }
      }
      else {
        cerr << "Error parsing port module connections.\n";
        cerr << "Execution aborted.\n";
        exit(1);
      }
    }
  }
  else{
    cerr << "Could not open template/individual_ports.sv.\n";
    cerr << "Execution aborted.\n";
    exit(1);
  }
  port_file.close();

  return result;
}

string getTestbenchVarConcat(){
  string result = "";
  string line;
  int var_count = 0;

  ifstream port_file("template/individual_ports.sv");
  if(port_file.is_open())
  {
    while(getline(port_file,line))
    {
      if(line.find("input") != string::npos || line.find("output") != string::npos){
        // Get parameter name
        string param_name = "";
        std::size_t param_location = line.find_last_of(" ");
        if (param_location != std::string::npos){
          // Found start of parameter, lets get its name
          param_name = line.substr(param_location+1);
          //cout << param_name << "\n";
        }
        else{
          // Parameter not found, exit for now...
          cerr << "Error finding parameter name.\n";
          cerr << "Execution aborted.\n";
          exit(1);
        }

        // If param name is equal to "clk" or "rst", we can ignore as it is already declared
        if(param_name == "clk" || param_name == "rst"){
          continue;
        }
        else {
          if(line.find("input") != string::npos){
            if(var_count > 0){
              result += ", ";
            }
            result += param_name;
            var_count++;
          }
          // TODO: This line will probably need to be changed in the future
          else if(line.find("output") != string::npos){
            if(var_count > 0){
              result += ", ";
            }
            result += param_name + "_expected";
            var_count++;
          }
        }
      }
      else {
        cerr << "Error parsing port module connections.\n";
        cerr << "Execution aborted.\n";
        exit(1);
      }
    }
  }
  else{
    cerr << "Could not open template/individual_ports.sv.\n";
    cerr << "Execution aborted.\n";
    exit(1);
  }
  port_file.close();

  return result;
}

string getTaskInputs(){
  string result = "";
  string line;
  int var_count = 0;

  ifstream port_file("template/individual_ports.sv");
  if(port_file.is_open())
  {
    while(getline(port_file,line))
    {
      if(line.find("input") != string::npos || line.find("output") != string::npos){
        // Get parameter name
        string param_name = "";

        // Check if bus width is declared
        std::size_t bus_start = line.find("[");
        if (bus_start != std::string::npos){
          param_name = line.substr(bus_start);
        }
        else {
          std::size_t param_location = line.find_last_of(" ");
          if (param_location != std::string::npos){
            // Found start of parameter, lets get its name
            param_name = line.substr(param_location+1);
          }
          else{
            // Parameter not found, exit for now...
            cerr << "Error finding parameter name.\n";
            cerr << "Execution aborted.\n";
            exit(1);
          }
        }

        // If param name is equal to "clk" or "rst", we can ignore as it is already declared
        if(param_name == "clk" || param_name == "rst"){
          continue;
        }
        else {
          // Connections found
          if(var_count > 0){
            result += "\t\t";
          }
          result += "input " + param_name + "_value;\n";
          var_count++;
        }
      }
      else {
        cerr << "Error parsing port module connections.\n";
        cerr << "Execution aborted.\n";
        exit(1);
      }
    }
  }
  else{
    cerr << "Could not open template/individual_ports.sv.\n";
    cerr << "Execution aborted.\n";
    exit(1);
  }
  port_file.close();

  return result;
}

string assignTaskInputs(){
  string result = "";
  string line;
  int var_count = 0;

  ifstream port_file("template/individual_ports.sv");
  if(port_file.is_open())
  {
    while(getline(port_file,line))
    {
      if(line.find("input") != string::npos || line.find("output") != string::npos){
        // Get parameter name
        string param_name = "";

        // Check if bus width is declared
        std::size_t param_location = line.find_last_of(" ");
        if (param_location != std::string::npos){
          // Found start of parameter, lets get its name
          param_name = line.substr(param_location+1);
        }
        else{
          // Parameter not found, exit for now...
          cerr << "Error finding parameter name.\n";
          cerr << "Execution aborted.\n";
          exit(1);
        }

        // If param name is equal to "clk" or "rst", we can ignore as it is already declared
        if(param_name == "clk" || param_name == "rst"){
          continue;
        }
        else if(line.find("output") != string::npos){
          continue;
        }
        else {
          if(line.find("input") != string::npos){
            result += "\t\t" + param_name + "=" + param_name + "_value;\n";
            var_count++;
          }
        }
      }
      else {
        cerr << "Error parsing port module connections.\n";
        cerr << "Execution aborted.\n";
        exit(1);
      }
    }
  }
  else{
    cerr << "Could not open template/individual_ports.sv.\n";
    cerr << "Execution aborted.\n";
    exit(1);
  }
  port_file.close();

  return result;
}

string initializePreviousStateRegisters(int id){
  string result = "";
  string line;
  int var_count = 0;

  ifstream port_file("template/individual_ports.sv");
  if(port_file.is_open())
  {
    while(getline(port_file,line))
    {
      if(line.find("input") != string::npos || line.find("output") != string::npos){
        // Get parameter name
        string param_name = "";

        // Check if bus width is declared
        std::size_t bus_start = line.find("[");
        if (bus_start != std::string::npos){
          param_name = line.substr(bus_start);
        }
        // If not, still get the parameter name
        else {
          std::size_t param_location = line.find_last_of(" ");
          if (param_location != std::string::npos){
            // Found start of parameter, lets get its name
            param_name = line.substr(param_location+1);
          }
          else{
            // Parameter not found, exit for now...
            cerr << "Error finding parameter name.\n";
            cerr << "Execution aborted.\n";
            exit(1);
          }
        }

        // If param name is equal to "clk" or "rst", we can ignore as it is already declared
        if(param_name == "clk" || param_name == "rst"){
          continue;
        }
        else {
          // Connections found
          if(line.find("output reg") != string::npos){
            result += "\t\t\t" + param_name + "_previous[" + to_string(id) + "] = 1'b0;\n";
            var_count++;
          }
        }
      }
      else {
        cerr << "Error parsing port previous state registers\n";
        cerr << "Execution aborted.\n";
        exit(1);
      }
    }
  }
  else{
    cerr << "Could not open template/individual_ports.sv.\n";
    cerr << "Execution aborted.\n";
    exit(1);
  }
  port_file.close();

  return result;
}

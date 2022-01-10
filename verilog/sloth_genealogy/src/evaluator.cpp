#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <assert.h>
#include <math.h>
#include <algorithm>    

#include <iterator>
#include <string>
#include <bits/stdc++.h>


#include <ga/ga.h>
#include <GE/ge.h>

// Include our custom header so we can access the _evaluated flag of a genome
#include "../include/GAGenomeMulti.h"

// Set this flag to evaluate each genome only once
// Remove if you wish for the genome to be evaluated every time
//#define SINGLE_EVAL

using namespace std;

// GE mapper, declared in main.cpp
extern GEGrammarSI mapper;

// Function Prototypes
void createIndividual(GAGenome &g, unsigned long id);
void createTestbench(GAPopulation &p);

void OriginalapplySloth();
void applySloth(float percentile);
void editDistance(int population_size);
string readFileIntoString(const string& path);
int EditDistDP(string str1, string str2);

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
  
  //Calculates Edit Distance of Phenotypes
  //editDistance(p.size());

  // If an individual needs to be evaluated, run the testbench and get a score
  if(run_testbench){
    // Create the testbench.sv file so that we can run the simulation
    createTestbench(p);

    // Evaluate the testbench.sv file so that we get scores
    // Uncomment to run the appropriate simulator
    evaluateTestbenchIcarus();
    //evaluateTestbenchVivado(p);
    //evaluateTestbenchModelsim(p);
    
    // Diversity
    //cout << "Diversity: " << p.div() << "\n" ;

    //SLOTH 
    ifstream slothFile("tmp/sloth");
    
    if(slothFile){
      
      float percentile = 0;
      while(slothFile >> percentile){
        
          if(percentile >= 1){
            percentile = 0.99;
            }
          
          if(percentile < 0){
            percentile = 0.0;
          }
          
          cout << "Percentile from file: " << percentile << endl;
          applySloth(percentile);	
        }
    
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
//
// Invalid Phenotype error handle proposed by Samuel 03/12/2020 
//
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
    
    
    // Create file handler to save the core of this individual as the last valid one 
	FILE *last_valid;
	
	//Create output file for last valid
    string filename_LV = "tmp/last_valid.sv";
    if(!(last_valid=fopen(filename_LV.c_str(),"w")))
    {
      cerr << "Could not open " + filename_LV + "\n";
      cerr << "Execution aborted.\n";
      exit(1);
    }
	
	// Write phenotype code to file
    fprintf(last_valid,"%s",phenotype->getString().c_str());
	
	// Close the file
    fclose(last_valid);

  }
  else 
  {
    // We have a mapping error. Replace individual with last valid one
    
	//Debugging:
	//cerr << "\nError: Phenotype not valid. Replacing individual " + to_string(id) + "\n";
	
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
	
	// Write the last valid individual to file
	
	string line;
	ifstream LVfile("tmp/last_valid.sv");
	if (LVfile.is_open())
	{
		while (getline(LVfile,line) )
		{
			fprintf(file,"%s",line.c_str());
		}
    LVfile.close();

	}
    
	// Write end buffer to file
    fprintf(file,"%s",end_module.c_str());

    // Close the file
    fclose(file);
	
  }
}

// Create the testbench that instantiates the number of individuals
// in the population
void createTestbench(GAPopulation &p){
  // Use ofstream to write to testbench.sv
  ofstream file;
  string line;

  // Open the file
  file.open("tmp/testbench.sv");

  // Check that the file opened correctly. If not, then exit.
  if(!file.is_open())
  {
    cerr << "Could not open tmp/testbench.sv.\n";
    cerr << "Execution aborted.\n";
    exit(1);
  }

  // Time to piece together our testbench
  // First include all the individuals
  file << "// Include all individivuals" << endl;
  for (int id = 0; id < p.size(); id++){
#ifdef SINGLE_EVAL
    if(reinterpret_cast<GAGenomeMulti*>(&p.individual(id))->getEvaluated() == 0){
#endif
      string include = "\`include \"tmp/individual_" + to_string(id) + ".sv\"\n";
      file << include;
#ifdef SINGLE_EVAL
    }
#endif
  }
  file << endl;

  // Include the necessary definitions
  file << "// Definitions" << endl;
  // Population size
  string define_population = "\`define POPULATION_SIZE " + to_string(p.size()) + "\n";
  file << define_population;
  // Number of tests
  // We need to check test_vectors.tv to count how many tests there are
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
  string define_number_of_tests = "\`define TEST_COUNT " + to_string(line_count) + "\n";
  file << define_number_of_tests;
  // Clock period
  string define_period = "\`define PERIOD 10\n";
  file << define_period;
  file << endl;

  // Include the start of the general testbench
  ifstream testbench_start("template/testbench_start.sv");
  if(testbench_start.is_open())
  {
    while(getline(testbench_start,line))
    {
      file << line << endl;
    }
  }
  else{
    cerr << "Could not open template/testbench_start.sv.\n";
    cerr << "Execution aborted.\n";
    exit(1);
  }
  testbench_start.close();

  // Create the variables required to connect the DUT to the testbench
  string variables = getTestbenchVar();
  file << variables << endl;
  
  // Create an array to store the expected results
  int port_count = getPortCount();
  file << "\t// Array of testvectors to store expected values" << endl;
  file << "\treg [" + to_string((16*port_count)-1) + ":0] testvectors[0:(`TEST_COUNT-1)];" << endl;
  file << "\tinteger vectornum = 0;" << endl << endl;

  // Instantiate the individuals
  file << "\t// Instantiate all the individuals" << endl;
  for (int id = 0; id < p.size(); id++){
#ifdef SINGLE_EVAL
    if(reinterpret_cast<GAGenomeMulti*>(&p.individual(id))->getEvaluated() == 0){
#endif
      //string connections = ".a(a),.b(b),.ci(ci),.sum(sum_current[" + to_string(id) + "]),.co(co_current[" + to_string(id) + "])";
      string connections = getPortNameTestbench(id);
      string instantiate = "  individual_" + to_string(id) + " dut_" + to_string(id) + "(" + connections + ");\n";
      file << instantiate;
#ifdef SINGLE_EVAL
    }
#endif
  }
  file << endl;

  // Include the testcase
  file << "\t// Create task to evaluate each testcase\n";
  file << "\t// Note that this evaluates the entire population for this testcase\n";
  file << "\ttask testcase;\n";
  file << "\t\t" << getTaskInputs() << "\n";
  file << endl;
  file << "\t\t// Initialise inputs\n";
  file <<  assignTaskInputs() << "\n";
  //file << "\t\t#(`PERIOD/2) // Wait till negative clock edge to check signals\n";
  file << "\t\tfor(int i = 0; i < `POPULATION_SIZE; i++) begin\n";

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

  file << "\t\tend\n";
  file << "\tendtask\n\n";

  // Read in values from testvectors and assign at negedge
  string assign_str = getTestbenchVarConcat();
  file << "\t// We want to change our inputs on negedge so that we can run testcases at posedge\n";
  file << "\talways @(posedge clk) begin\n";
  file << "\t\tif (rst == 0) begin\n";
  file << "\t\t\t{" + assign_str + "} = testvectors[vectornum];\n";
  file << "\t\t\tvectornum = vectornum + 1;\n";
  file << "\t\tend" << endl << endl;
  file << "\tend" << endl << endl;

  file << "\talways @(posedge clk) begin\n";
  file << "\t\tif (rst == 0) begin\n";
  file << "\t\t\ttestcase(" + assign_str + ");\n";
  file << "\t\tend" << endl << endl;
  file << "\tend" << endl << endl;

  // Include the rest of the general testbench
  ifstream testbench_end("template/testbench_end.sv");
  if(testbench_end.is_open())
  {
    while(getline(testbench_end,line))
    {
      file << line << endl;
    }
  }
  else{
    cerr << "Could not open template/testbench_end.sv.\n";
    cerr << "Execution aborted.\n";
    exit(1);
  }
  testbench_end.close();

  // Close the file
  file.close();
}

// Functions to evaluate the testbench using Icarus, Modelsim or Vivado

void evaluateTestbenchIcarus(){
  // Call the simulator - In this case Icarus Verilog
  system("echo 0 > tmp/results && iverilog -g2009 -o tmp/a.out tmp/testbench.sv && tmp/a.out > tmp/results");
}



  
void OriginalapplySloth(){

vector<int> results;

 // open file    
ifstream inputFile("tmp/results");

// test file open   
if (inputFile) {        
    int value;
    // read the elements in the file into a vector  
    while ( inputFile >> value ) {
        results.push_back(value);
    }
}

inputFile.close();

// Declaring new vector 
vector<int> sorted; 
  
// Copying vector by copy function 
copy(results.begin(), results.end(), back_inserter(sorted)); 

// Sorting the results inside the sorted vector
sort(sorted.begin(), sorted.end());

// Finding the max score of this population
double max = *max_element(results.begin(), results.end());

float p = 0.5;   //PERCENTILE HERE NOT IN USE (SIMPLE SLOTH)
int index = floor(p*sorted.size()); 
int sloth = sorted[index];
cout<< "Sloth:" << sloth << endl; // Will print the score value of the sloth

// Finds the index of the sloth in the results vector
auto it = find(results.begin(), results.end(), sloth);
int index2 = it - results.begin();

// Changes the score of the sloth at the results vector to the max score
results.at(index2) = max;

// Saves back the results to the file
std::ofstream outFile("tmp/results");
for (const auto &e : results) outFile << e << "\n";

}

void applySloth(float percentile){
  
  
  cout << "sloth! " << percentile << endl;
  
  vector<int> results;
  
  // open file    
  ifstream inputFile("tmp/results");
  
  // test file open   
  if (inputFile) {        
    int value;
    // read the elements in the file into a vector  
    while ( inputFile >> value ) {
      results.push_back(value);
    }
  }
  
  inputFile.close();
  
  // Declaring new vector 
  vector<int> sorted; 
  
  // Copying vector by copy function 
  copy(results.begin(), results.end(), back_inserter(sorted)); 
  
  // Sorting the results inside the sorted vector
  sort(sorted.begin(), sorted.end());
  
  // Finding the max score of this population
  double max = *max_element(results.begin(), results.end());
  
  float p = percentile;   //Percentile here (0 to 1)
  int index = floor(p*sorted.size()); 
  int sloth = sorted[index];
  //cout<< "Sloth:" << sloth << endl; // Will print the score value of the sloth
  //cout<< "Index:" << index << endl;
  // Finds the index of the sloth in the results vector
  auto it = find(results.begin(), results.end(), sloth);
  int index2 = it - results.begin();
  
  // Changes the score of the sloths at the results vector to the max score
  for (unsigned i=0; i<results.size(); i++){ // Go through the results
    
    if((results[i] <= sloth) && (index > 0)){ 
      // If score is less than or equal Sloth
      // This will limit the number of sloths to only "index"
      
      //cout<< "Swapping " << results[i] << " for " << max << " at individual " << i << endl;
      results[i] = max;       // Swap score to max score    
      index = index - 1;      // Subtract 1 from remaining sloths to promote
      
    }
    
  }
  
  
  
  // Saves back the results to the file
  std::ofstream outFile("tmp/results");
  for (const auto &e : results) outFile << e << "\n";
  
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
  system("echo 0 > tmp/results && xsim testbench_sim -runall -nolog | sed '1,/run -all/d;/$finish/,$d' > tmp/results");

  // Clean up
  system("rm *.pb *.jou *.wdb && rm webtalk*");

  // Note - A small performance gain could be made here by not deleting the xsim.dir folder as Vivado needs to request a webtalk license every time a new folder is created.
  // We are deleting here to keep the root directory clean and the performance gain is minor
  system("rm -rf xsim.dir");
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
  system("echo 0 > tmp/results && vsim testbench -c -do \"run -all; exit\" -quiet -nolog -suppress 3116 | sed '1,/# run -all/d;/$finish/,$d' | sed 's/^..//' > tmp/results");

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
        cerr << "Error parsing port module connections (line 460).\n";
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
        cerr << "Error parsing port module connections (Line 496).\n";
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
        cerr << "Error parsing port module connections (line 580).\n";
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
        cerr << "Error parsing port module connections (line 645).\n";
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
  //int var_count = 0;

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
          //if(var_count > 0){
          //  result += ", ";
          //}
          result += "input " + param_name + "_value;\n";
          //var_count++;
        }
      }
      else {
        cerr << "Error parsing port module connections (line 708).\n";
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
        cerr << "Error parsing port module connections (line 765).\n";
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


// DIVERSITY STUFF

//Edit Distance
int EditDistDP(string str1, string str2){
  
  int len1 = str1.length();
  int len2 = str2.length();
  
  // Create a DP array to memoize result
  // of previous computations
  int DP[2][len1 + 1];
  
  // To fill the DP array with 0
  memset(DP, 0, sizeof DP);
  
  // Base condition when second string
  // is empty then we remove all characters
  for (int i = 0; i <= len1; i++)
    DP[0][i] = i;
  
  // Start filling the DP
  // This loop run for every
  // character in second string
  for (int i = 1; i <= len2; i++) {
    // This loop compares the char from
    // second string with first string
    // characters
    for (int j = 0; j <= len1; j++) {
      // if first string is empty then
      // we have to perform add character
      // operation to get second string
      if (j == 0)
        DP[i % 2][j] = i;
      
      // if character from both string
      // is same then we do not perform any
      // operation . here i % 2 is for bound
      // the row number.
      else if (str1[j - 1] == str2[i - 1]) {
        DP[i % 2][j] = DP[(i - 1) % 2][j - 1];
      }
      
      // if character from both string is
      // not same then we take the minimum
      // from three specified operation
      else {
        DP[i % 2][j] = 1 + min(DP[(i - 1) % 2][j],
                               min(DP[i % 2][j - 1],
                                   DP[(i - 1) % 2][j - 1]));
      }
    }
  }
  
  // after complete fill the DP array
  // if the len2 is even then we end
  // up in the 0th row else we end up
  // in the 1th row so we take len2 % 2
  // to get row
  return DP[len2 % 2][len1];
}

string readFileIntoString(const string& path) {
  ifstream input_file(path);
  if (!input_file.is_open()) {
    cerr << "Could not open the file - '"
         << path << "'" << endl;
    exit(EXIT_FAILURE);
  }
  return string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}

#define MIN(x,y) ((x) < (y) ? (x) : (y)) //calculate minimum between two values

// Calculates the Average Edit Distance (phenotype) of a given population
void editDistance(int population_size)
{
  
  string file_1;
  string file_2;
  
  // file_1 = readFileIntoString("tmp/individual_0.sv");
  // file_2 = readFileIntoString("tmp/individual_4.sv");
  
  // EditDistDP(file_1, file_2);
  
  // levenshtein(file_1, file_2);
  
  int popsize = population_size;
  int results[popsize][popsize];
  float sum = 0.0;
  
  for(int row = 0; row < popsize; row++){
    string ind1 = "individual_" + to_string(row) + ".sv";
    
    for(int column = 0; column < popsize; column++){
      string ind2 = "individual_" + to_string(column) + ".sv";  
      //cout << ind1 << " vs " << ind2 << endl;
      
      file_1 = readFileIntoString("tmp/" + ind1);
      file_2 = readFileIntoString("tmp/" + ind2);
      
      results[row][column] = EditDistDP(file_1, file_2);
      
      sum = sum + results[row][column];
      
      //cout << results[row][column] << endl;
      //cout << "Sum: " << sum << endl;
      
      
      
      //levenshtein(file_1, file_2);
      
    }
    
  }
  
  float diversity = sum/(popsize*popsize);
  
  // Create file handler
  FILE *file;
  
  //Create output file
  string filename = "log/edit_distance";
  if(!(file=fopen(filename.c_str(),"a")))
  {
    cerr << "Could not open " + filename + "\n";
    cerr << "Execution aborted.\n";
    exit(1);
  }else{
    
    
    // Write diversity score to file
    fprintf(file,"%f", diversity);
    fprintf(file,"%s", "\n");
    
    // Close the file
    fclose(file);
    
    // Same for PID
    std::ofstream outFile("tmp/current_diversity");
    outFile << diversity << "\n";
    
  }
  
  
  //cout << "Div Score: " << diversity << endl;
  
}



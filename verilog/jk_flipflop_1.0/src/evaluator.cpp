#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>

#include <ga/ga.h>
#include <GE/ge.h>

#include "../include/GAGenomeMulti.h"

#define ONCE

using namespace std;

// GE mapper, declared in main.cpp
extern GEGrammarSI mapper;

// Function Prototypes
void createIndividual(GAGenome &g, unsigned long id);
void createTestbench(GAPopulation &p);
void evaluateTestbenchIcarus();
void evaluateTestbenchVivado(GAPopulation &p);

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
#ifdef ONCE
    if(reinterpret_cast<GAGenomeMulti*>(&p.individual(id))->getEvaluated() == 0){
#endif
      createIndividual(p.individual(id), id);
      run_testbench = true;
#ifdef ONCE
    }
#endif
  }

  // If an individual needs to be evaluated, run the testbench and get a score
  if(run_testbench){
    // Create the testbench.sv file so that we can run the simulation
    createTestbench(p);

    // Evaluate the testbench.sv file so that we get scores
    evaluateTestbenchIcarus();
    //evaluateTestbenchVivado(p);

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
#ifdef ONCE
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
#ifdef ONCE
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

  // Old shite
  // Assign the fitness scores back to the individuals so GALib can perform
  // mutation and crossover
  //for (int i = 0; i < p.size(); i++){
  // NOTE: We can't set nevals, as it is protected.
  //       This shouldn't matter as it is only a statistic
  //p.individual(i).score(i);
  //}
}

// Work functions here

// Create an individual in tmp and assign a unique ID
// so we can include each one in the testbench
void createIndividual(GAGenome &g, unsigned long id){
  GEListGenome &genome = static_cast<GEListGenome&>(g);
  //Assign genotype to mapper
  mapper.setGenotype(genome);
  
  //cout << *mapper.getGenotype() << endl;
  //cout << *mapper.getPhenotype() << endl;

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

    // Read in start and end module
    ifstream individual_start { "template/individual_start.sv" };
    string start_module { istreambuf_iterator<char>(individual_start), istreambuf_iterator<char>() };
    start_module.insert(0,"module individual_"+to_string(id));

    ifstream individual_end { "template/individual_end.sv" };
    string end_module { istreambuf_iterator<char>(individual_end), istreambuf_iterator<char>() };

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
#ifdef ONCE
    if(reinterpret_cast<GAGenomeMulti*>(&p.individual(id))->getEvaluated() == 0){
#endif
      string include = "\`include \"tmp/individual_" + to_string(id) + ".sv\"\n";
      file << include;
#ifdef ONCE
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
  // We need to check examples.tv to count how many tests there are
  int line_count = 0;
  ifstream number_of_tests("src/example.tv");
  if(number_of_tests.is_open()){
    while(getline(number_of_tests,line))
    {
      if(!number_of_tests.eof()){
        line_count++;
      }
    }
  }
  else{
    cerr << "Could not open src/example.tv.\n";
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

  // Instantiate the individuals
  file << "// Instantiate all the individuals" << endl;
  for (int id = 0; id < p.size(); id++){
#ifdef ONCE
    if(reinterpret_cast<GAGenomeMulti*>(&p.individual(id))->getEvaluated() == 0){
#endif
      string connections = ".q(q_current[" + to_string(id) + "]),.clk(clk),.rst(rst),.j(j),.k(k)";
      string instantiate = "  individual_" + to_string(id) + " dut_" + to_string(id) + "(" + connections + ");\n";
      file << instantiate;
#ifdef ONCE
    }
#endif
  }
  file << endl;

  // Include the testcase
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

void evaluateTestbenchIcarus(){
  // Call the simulator - In this case Icarus Verilog
  system("echo 0 > tmp/results && iverilog -g2009 -o tmp/a.out tmp/testbench.sv && tmp/a.out | tail -n+2 > tmp/results");
}

void evaluateTestbenchVivado(GAPopulation &p){
  // Check which individuals need to be parsed
  string parse_individuals = "";
  for (int id = 0; id < p.size(); id++){
#ifdef ONCE
    if(reinterpret_cast<GAGenomeMulti*>(&p.individual(id))->getEvaluated() == 0){
#endif
      parse_individuals += "tmp/individual_" + to_string(id) + ".sv ";
#ifdef ONCE
    }
#endif
  }
  // Parse design files
  string parse_command = "xvlog -sv " + parse_individuals + " && xvlog -sv tmp/testbench.sv";
  system(parse_command.c_str());

  // Elaborate and Generate a design snapshot
  system("xelab -debug typical fulladder_tb -s fulladder_tb_sim");

  // Call the simulator
  system("echo 0 > tmp/results && xsim fulladder_tb_sim -runall | sed '1,/run -all/d;/$finish/,$d' > tmp/results");
}

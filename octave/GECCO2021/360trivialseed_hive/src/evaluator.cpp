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
//#define SINGLE_EVAL

using namespace std;

// GE mapper, declared in main.cpp
extern GEGrammarSI mapper;

// Function Prototypes
void createIndividual(GAGenome &g, unsigned long id);
void createTestbench(GAPopulation &p);

// Simulator Prototypes

void evaluateTestbenchOctave();

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

  // If an individual needs to be evaluated, run the testbench and get a score
  if(run_testbench){
    // Create the testbench.sv file so that we can run the simulation
  
	createTestbench(p);

    // Evaluate the testbench.sv file so that we get scores
    // Uncomment to run the appropriate simulator
    //evaluateTestbenchIcarus();
    //evaluateTestbenchVivado(p);
    //evaluateTestbenchModelsim(p);
	evaluateTestbenchOctave();

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
      cerr << "Could not open tmp/results \n";
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
    string filename = "tmp/individual_" + to_string(id) + ".m";
    
	if(!(file=fopen(filename.c_str(),"w")))
    {
      cerr << "Could not open " + filename + "\n";
      cerr << "Execution aborted.\n";
      exit(1);
    }

    string start_module = "function [expression] = individual_"+to_string(id)+"()\n";
   
   // Write start buffer to file
    fprintf(file,"%s",start_module.c_str());
    // Write phenotype code to file
    fprintf(file,"%s",phenotype->getString().c_str());

    // Close the file
    fclose(file);
    
    
    // Create file handler to save the core of this individual as the last valid one 
	FILE *last_valid;
	
	//Create output file for last valid
    string filename_LV = "tmp/last_valid.m";
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
     
	 // We have a mapping error. Needs to be handled. Exit for now
   //cerr << "Error: Phenotype not valid.\n";
   // cerr << "Execution aborted.\n";
    //exit(1);
	
	
	
	// We have a mapping error. Replace individual with last valid one
    
	//Debugging:
	//cerr << "\nError: Phenotype not valid. Replacing individual " + to_string(id) + "\n";
	
	// Create file handler
 /*    FILE *file;

    //Create output file
    string filename = "tmp/individual_" + to_string(id) + ".m";
    
	if(!(file=fopen(filename.c_str(),"w")))
    {
      cerr << "Could not open " + filename + "\n";
      cerr << "Execution aborted.\n";
      exit(1);
    }

    string start_module = "function [expression] = individual_"+to_string(id)+"()\n";

    // Write start buffer to file
    fprintf(file,"%s",start_module.c_str());
	
	// Write the last valid individual to file
	
	string line;
	ifstream LVfile("tmp/last_valid.m");
	if (LVfile.is_open())
	{
		while (getline(LVfile,line) )
		{
			fprintf(file,"%s",line.c_str());
		}
    LVfile.close();

	}
    
    // Close the file
    fclose(file); */
	
  }
}

// Create the testbench that instantiates the number of individuals
// in the population
void createTestbench(GAPopulation &p){
  // Use ofstream to write to testbench.sv
  ofstream file;
  string line;

  // Open the file
  file.open("tmp/testbench.m");

  // Check that the file opened correctly. If not, then exit.
  if(!file.is_open())
  {
    cerr << "Could not open tmp/testbench.m.\n";
    cerr << "Execution aborted.\n";
    exit(1);
  }

  // Time to piece together our testbench
  
  file << "clear all" << endl;
  // First include all the individuals
  file << "% Include all individivuals" << endl;
  for (int id = 0; id < p.size(); id++){
#ifdef SINGLE_EVAL
    if(reinterpret_cast<GAGenomeMulti*>(&p.individual(id))->getEvaluated() == 0){
#endif
      string include = "#<include>individual_" + to_string(id) + ".m</include>\n";
      file << include;
#ifdef SINGLE_EVAL
    }
#endif
  }
  file << endl;

  // Include the necessary definitions
  file << "%Definitions" << endl;
  // Population size
  string define_population = "POPULATION_SIZE=" + to_string(p.size()) + ";\n";
  file << define_population;
  
  // Include the start of the general testbench
  ifstream testbench_start("template/testbench_start.m");
  if(testbench_start.is_open())
  {
    while(getline(testbench_start,line))
    {
      file << line << endl;
    }
  }
  else{
    cerr << "Could not open template/testbench_start.m.\n";
    cerr << "Execution aborted.\n";
    exit(1);
  }
  testbench_start.close();

  // Close the file
  file.close();
}

// Functions to evaluate the testbench using Octave, Icarus, Modelsim or Vivado

void evaluateTestbenchOctave(){
  // Call the simulator - In this case Octave
  system("cd tmp/ && octave testbench.m && cd ..");
}



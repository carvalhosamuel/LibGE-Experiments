#ifndef _MAIN_CPP_
#define _MAIN_CPP_

#include <iostream>
#include <string>
#include <ga/ga.h>
#include <GE/ge.h>

// added to measure time
#include <chrono>

// OpenMP library
#include <omp.h>

// Include the custom GA Steady State class
#include "../include/GASStateGAMulti.h"

using namespace std::chrono;

// Function prototypes
float app_init(unsigned int wrappingEvents,string grammarFile);
float objfunc(GAGenome&);
void initFuncRandom(GAGenome&);
void initFuncSI(GAGenome&);
void print_individual(const GAGenome &g);
int PointMutator(GAGenome&, float);

// Static mapper for initialisation and evaluation of individuals
GEGrammarSI mapper;
// Parameters for Random Initialisation function.
unsigned int minSize=15; // Minimum size for Random Initialisation.
unsigned int maxSize=25; // Minimum size for Random Initialisation.

// Select simulator (Icarus as default)
std::string simulator = "icarus";

// Number of Objective function calls
int obj_calls = 0;

// Function prototype for custom evaluator
void customInitializer(GAPopulation &p);
void customEvaluator(GAPopulation &p);
float emptyEvaluator(GAGenome&);

/* ---- Main ----- */
int main(int argc, char **argv){
    // added to measure time
    auto start = high_resolution_clock::now();

    // Create directory to hold temporary files in ./tmp and ensure it is empty
    system("rm -rf ./tmp/* && mkdir -p ./tmp" );
    
    // Print version of libGE used
    cout << "Using libGE version " << libGEVersion << endl;
    // Parse command-line for options not taken care by GAParameterList
    unsigned int seed=1; // Random seed.
    string grammarFile("grammar/grammar.bnf"); // Grammar file.
    unsigned int wrappingEvents=50; // Wrapping events.
    bool sensibleInit=true; // Use Sensible Initialisation.
    float grow=0.5; // Grow rate for Sensible Initialisation.
    unsigned int maxDepth=10; // Maximum tree depth for Sensible Initialisation.
    unsigned int tailSize=0; // Tail size for Sensible Initialisation.
    float tailRatio = 0.0; // Tail ratio for Sensible Initialisation.
    bool effectiveXO=false; // Use Effective Crossover.
    std::string settingsFile; // The GALib settings file.

    // Set default population and generation sizes
    unsigned int pop = 10;
    unsigned int gen = 5;

    // Loop to get parameters
    for(int ii=1; ii<argc; ii++){
      if(strcmp(argv[ii],"sim")==0){
				simulator=argv[++ii];
      }
      if(strcmp(argv[ii],"pop")==0){
				pop=atoi(argv[++ii]);
      }
      if(strcmp(argv[ii],"gen")==0){
				gen=atoi(argv[++ii]);
      }
      if(strcmp(argv[ii],"seed")==0){
				seed=atoi(argv[++ii]);
      }
      else if(strcmp(argv[ii],"grammar")==0){
				grammarFile=argv[++ii];
      }
      else if(strcmp(argv[ii],"wrap")==0){
				wrappingEvents=atoi(argv[++ii]);
      }
      else if(strcmp(argv[ii],"sensible")==0){
				sensibleInit=atoi(argv[++ii]);
      }
      else if(strcmp(argv[ii],"min")==0){
				minSize=atoi(argv[++ii]);
      }
      else if(strcmp(argv[ii],"max")==0){
				maxSize=atoi(argv[++ii]);
      }
      else if(strcmp(argv[ii],"grow")==0){
				grow=atof(argv[++ii]);
      }
      else if(strcmp(argv[ii],"maxDepth")==0){
				maxDepth=atoi(argv[++ii]);
      }
      else if(strcmp(argv[ii],"tailSize")==0){
				tailSize=atoi(argv[++ii]);
      }
      else if(strcmp(argv[ii],"tailRatio")==0){
				tailRatio=atof(argv[++ii]);
      }
      else if(strcmp(argv[ii],"effective")==0){
				effectiveXO=atoi(argv[++ii]);
      }
      else if(strcmp(argv[ii],"settings_file")==0){
				settingsFile=(argv[++ii]);
      }
    }

    cout << "Using simulator: " << simulator << endl;

    // Register default values of parameters.
    GAParameterList params;
    GASteadyStateGA::registerDefaultParameters(params);
    params.set(gaNpopulationSize,pop); // Population size.
    params.set(gaNnGenerations,gen); // Number of generations.
    params.set(gaNpCrossover,0.9); // Probability of crossover.
    params.set(gaNpMutation,0.01); // Probability of mutation.
    params.set(gaNpReplacement,1.0); // Replacement strategy for steady-state GA
    params.set(gaNscoreFrequency,1); // How often to record scores.
    params.set(gaNflushFrequency,1); // How often to dump scores to file.
    params.set(gaNscoreFilename,"log/output_data.log"); // Output data file.
    // Grab values from file first.
    if (settingsFile.size() > 0) {
      std::cout << "Loading settings file '" << settingsFile 
		<< "'." << std::endl;
      params.read(settingsFile.c_str());
    }
    params.parse(argc,argv,gaFalse); // Parse command line for GAlib args.
    
    // Create genome
    //GAListGenome<unsigned char> genome(objfunc);
    GEListGenome genome;

    // Not needed as we want to evaluate on a population basis
    // genome.evaluator(objfunc);
    
    // Initialization is still done on an individual basis
    // Use our initialisation function (initFuncRandom or initFuncSI).
    if(!sensibleInit){
      std::cout << "Using random initialisation." << std::endl; 
      genome.initializer(::initFuncRandom);
    }
    else{
      std::cout << "Using sensible initialisation." << std::endl;
      genome.initializer(::initFuncSI);
    }
    // THIS SHOULD BECOME REDUNDANT TO HERE

    // Use the one-point xo from GALib, or our effective version.
    if(!effectiveXO){
      std::cout << "Using one point crossover." << std::endl;
      genome.crossover(GEListGenome::OnePointCrossover);
    }
    else{
      std::cout << "Using effective crossover." << std::endl;
      genome.crossover(GEListGenome::effCrossover);
    }

    //Use our point-mutation.
    genome.mutator(GEListGenome::pointMutator);
    
    //Initialise libGE mapper.
    app_init(wrappingEvents,grammarFile);
    
    // Create GA with a steady-state approach.
    GASteadyStateGAMulti ga(genome);

    // Set the custom initializer - Same as default in this case
    ga.setInitializer(customInitializer); 
    
    // Set the population based evaluator
    ga.setEvaluator(customEvaluator); 

    // Associate parameters.
    ga.parameters(params);

    // Mapper settings.
    mapper.setGenotypeMaxCodonValue(UCHAR_MAX);
    mapper.setPopSize(ga.populationSize());
    mapper.setGrow(grow);
    mapper.setMaxDepth(maxDepth);
    if(tailSize){
      mapper.setTailSize(tailSize);
    }
    else{
      mapper.setTailRatio(tailRatio);
    }
    
    // Stats settings.
    ga.set(gaNselectScores,
    // Which scores should we track?      
	  GAStatistics::AllScores);
    
    // Stats file.
    ofstream stats("log/statistics.log");
    
    // Apply all settings to ga, including random seed
    ga.initialize(seed);

    // Print out garan2 to see that the random seed is the same up to this point
    cout << "Random Seed: " << GAGetRandomSeed() << endl;
    
    // Evolutionary cycle
    int j=0;
    cout << "Generations: ";
    while(!ga.done()){
      ga.step();
      cout << ++j << " ";
      cout.flush();
      stats << ga.statistics().generation() << "\t"
	    << obj_calls << "\t"
	    << ga.statistics().current(GAStatistics::Maximum) << "\t"
	    << ga.statistics().current(GAStatistics::Mean) << "\t"
	    << ga.statistics().current(GAStatistics::Minimum) << "\n";
    }
    cout << endl;

    //Output statistics
    cout << ga.statistics() << endl;
    
    //Print best individual
    print_individual(ga.statistics().bestIndividual());
    
    // added to measure time
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<seconds>(stop - start);
    int seconds = duration.count();
    int minutes = seconds/60;
    int hours = minutes/60;
    std::cout<< "Time taken: " << hours%60 
     << ":" << minutes%60 << ":" << seconds%60 << " -> " << hours%60 << " hours, " << minutes%60 << " minutes, " << seconds%60 << " seconds.\n";
    std::chrono::duration<double> diff = stop - start;
    std::cout<<diff.count()<<endl; 
    return 0;
}

#endif

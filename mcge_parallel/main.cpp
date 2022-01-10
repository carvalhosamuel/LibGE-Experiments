/* main.cpp -*- C++ -*-
 * IntertwinedSpiral
 */

#ifndef _MAIN_CPP_
#define _MAIN_CPP_

#include <GE/ge.h>
#include <ga/ga.h>
#include <iostream>
#include <string>
// added to measure time
#include <chrono>
// OpenMP library
#include <omp.h>

using namespace std::chrono;

// Function prototypes
float app_init(unsigned int wrappingEvents, string grammarFile);
float objfunc(GAGenome &);
void initFuncRandom(GAGenome &);
void initFuncSI(GAGenome &);
void print_individual(const GAGenome &g);
int PointMutator(GAGenome &, float);

// Static mapper for initialisation and evaluation of individuals
GEGrammarSI mapper;
// Parameters for Random Initialisation function.
unsigned int minSize = 4; // Minimum size for Random Initialisation.
unsigned int maxSize = 50; // Maximum size for Random Initialisation.

// Number of Objective function calls
int obj_calls = 0;

/* ---- Main ----- */
int main(int argc, char **argv) {

  // added to measure time
  auto start = high_resolution_clock::now();

  // Print version of libGE used
  cout << "Using libGE version " << libGEVersion << endl;
  // Parse command-line for options not taken care by GAParameterList
  unsigned int seed = 0;             // Random seed.
  string grammarFile("grammar.bnf"); // Grammar file.
  unsigned int wrappingEvents = 0;   // Wrapping events.
  bool sensibleInit = false;         // Use Sensible Initialisation.
  float grow = 0.5;                  // Grow rate for Sensible Initialisation.
  unsigned int maxDepth = 10; // Maximum tree depth for Sensible Initialisation.
  unsigned int tailSize = 0;  // Tail size for Sensible Initialisation.
  float tailRatio = 0.0;      // Tail ratio for Sensible Initialisation.
  bool effectiveXO = false;   // Use Effective Crossover.
  std::string settingsFile;   // The GALib settings file.
  bool runapp = false;        // Use Shiny app or not?

   // Set default population and generation sizes
    unsigned int pop = 300;
    unsigned int gen = 300;
   // Set default mutation and crossover probabilities 
    float mut  = 0.1;
    float xover= 0.85;

    // Loop to get parameters
    for(int ii=1; ii<argc; ii++){
      if(strcmp(argv[ii],"pop")==0){
				pop=atoi(argv[++ii]);
      }
      if(strcmp(argv[ii],"gen")==0){
				gen=atoi(argv[++ii]);
      }
      if(strcmp(argv[ii],"seed")==0){
				seed=atoi(argv[++ii]);
      }
      else if(strcmp(argv[ii],"mut")==0){
				mut=atof(argv[++ii]);
      }
      else if(strcmp(argv[ii],"xover")==0){
				xover=atof(argv[++ii]);
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
      else if(strcmp(argv[ii],"app")==0){
        runapp=true;
      }
     
    }

  // Register default values of parameters.
  GAParameterList params;
  GASteadyStateGA::registerDefaultParameters(params);
  params.set(gaNpopulationSize, pop); // Population size.
  params.set(gaNnGenerations, gen);    // Number of generations.
  params.set(gaNpCrossover, xover);     // Probability of crossover.
  params.set(gaNpMutation, mut);     // Probability of mutation.
  params.set(gaNpReplacement, 1.0); // Replacement strategy for steady-state GA
  params.set(gaNscoreFrequency, 1); // How often to record scores.
  params.set(gaNflushFrequency, 1); // How often to dump scores to file.
  params.set(gaNrecordDiversity,gaTrue); // Record diversity
  params.set(gaNscoreFilename, "log/output_data.log"); // Output data file.
  params.set(gaNminimaxi, -1);
  // Grab values from file first.
  if (settingsFile.size() > 0) {
    std::cout << "Loading settings file '" << settingsFile << "'." << std::endl;
    params.read(settingsFile.c_str());
  }
  params.parse(argc, argv, gaFalse); // Parse command line for GAlib args.

  // Create genome, and associate the IntertwinedSpiral objective function.
  // GAListGenome<unsigned char> genome(objfunc);
  GEListGenome genome;
  genome.evaluator(objfunc);

  // Use our initialisation function (initFuncRandom or initFuncSI).
  if (!sensibleInit) {
    std::cout << "Using random initialisation." << std::endl;
    genome.initializer(::initFuncRandom);
  } else {
    std::cout << "Using sensible initialisation." << std::endl;
    genome.initializer(::initFuncSI);
  }

  // Use the one-point xo from GALib, or our effective version.
  if (!effectiveXO) {
    std::cout << "Using one point crossover." << std::endl;
    genome.crossover(GEListGenome::OnePointCrossover);
  } else {
    std::cout << "Using effective crossover." << std::endl;
    genome.crossover(GEListGenome::effCrossover);
  }
  
   std::cout << "Using mutation: " << mut << std::endl;
   std::cout << "Using crossover: " << xover << std::endl;
   std::cout << "Using minSize: " << minSize << std::endl;
   std::cout << "Using maxSize: " << maxSize << std::endl;
   std::cout << "Using wraps: " << wrappingEvents << std::endl;

  // Use our point-mutation.
  genome.mutator(GEListGenome::pointMutator);

  // Initialise libGE mapper.
  app_init(wrappingEvents, grammarFile);

  // Create GA with a steady-state approach.
  GASteadyStateGA ga(genome);

  // Associate parameters.
  ga.parameters(params);

  // Mapper settings.
  mapper.setGenotypeMaxCodonValue(UCHAR_MAX);
  mapper.setPopSize(ga.populationSize());
  mapper.setGrow(grow);
  mapper.setMaxDepth(maxDepth);
  if (tailSize) {
    mapper.setTailSize(tailSize);
  } else {
    mapper.setTailRatio(tailRatio);
  }

  // Stats settings.
  ga.set(gaNselectScores,
         // Which scores should we track?
         GAStatistics::AllScores);

  // Stats file.
  ofstream stats("stats");

  // Apply all settings to ga, including random seed
  ga.initialize(seed);
  
  // Print out garan2 to see that the random seed is the same up to this point
  cout << "Random Seed: " << GAGetRandomSeed() << endl;

  // Initialize Shiny app
  if(runapp){
   system("sh runapp.sh &");
  }

  // Evolutionary cycle
  int j = 0;
  cout << "Generations: ";
  while (!ga.done()) {
    ga.step();
    cout << ++j << " ";
    cout.flush();
    stats << ga.statistics().generation() << "\t" << obj_calls << "\t"
          << ga.statistics().current(GAStatistics::Maximum) << "\t"
          << ga.statistics().current(GAStatistics::Mean) << "\t"
          << ga.statistics().current(GAStatistics::Minimum) << "\n";
  }
  cout << endl;

  // Output statistics
  cout << ga.statistics() << endl;

  // Print best individual
  print_individual(ga.statistics().bestIndividual());

  // added to measure time
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<seconds>(stop - start);
  int seconds = duration.count();
  int minutes = seconds / 60;
  int hours = minutes / 60;
  std::cout << "Time taken: " << hours % 60 << ":" << minutes % 60 << ":"
            << seconds % 60 << " -> " << hours % 60 << " hours, "
            << minutes % 60 << " minutes, " << seconds % 60 << " seconds.\n";
            
  // Killing R sessions 
  //system("for pid in $(ps -ef | awk '/shiny/ {print $2}'); do kill -9 $pid; done");          

  return 0;
}

#endif

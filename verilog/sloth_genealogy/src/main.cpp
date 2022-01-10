#ifndef _MAIN_CPP_
#define _MAIN_CPP_

#include <iostream>
#include <string>
#include "pid.h"
#include <stdio.h>
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

void print_genotype(const GAGenome &g);
void print_phenotype(const GAGenome &g);
int CustomCrossover(const GAGenome &p1, const GAGenome &p2,  GAGenome *c1, GAGenome *c2);

// Static mapper for initialisation and evaluation of individuals
GEGrammarSI mapper;
// Parameters for Random Initialisation function.
unsigned int minSize=15; // Minimum size for Random Initialisation.
unsigned int maxSize=25; // Minimum size for Random Initialisation.

// Number of Objective function calls
int obj_calls = 0;

// Function prototype for custom evaluator
void customInitializer(GAPopulation &p);
//void customEvaluator(GAPopulation &p);
void customEvaluator(GAPopulation &p);
float emptyEvaluator(GAGenome&);

void applySloth(float percentile);

/* ---- Main ----- */
int main(int argc, char **argv){
    // added to measure time
    auto start = high_resolution_clock::now();
    
    // Clean edit_distance file
    system("rm -rf ./log/edit_distance");
    
    // Create directory to hold temporary files in ./tmp and ensure it is empty
    system("rm -rf ./tmp/* && mkdir -p ./tmp" );
    
    // Print version of libGE used
    cout << "Using libGE version " << libGEVersion << endl;
    // Parse command-line for options not taken care by GAParameterList
    unsigned int seed=0; // Random seed.
    string grammarFile("grammar/grammar.bnf"); // Grammar file.
    unsigned int wrappingEvents=10; // Wrapping events.
    bool sensibleInit=true; // Use Sensible Initialisation.
    float grow=0.5; // Grow rate for Sensible Initialisation.
    unsigned int maxDepth=50; // Maximum tree depth for Sensible Initialisation.
    unsigned int tailSize=0; // Tail size for Sensible Initialisation.
    float tailRatio = 0.0; // Tail ratio for Sensible Initialisation.
    bool effectiveXO=false; // Use Effective Crossover.
    std::string settingsFile; // The GALib settings file.
    bool runapp = false; //Use Shiny app or not?
    bool usesloth = false; //Use Sloth or not?
    double percentile = 0.0; //Percentile for sloth
    
    // Set default population and generation sizes
    unsigned int pop = 100;
    unsigned int gen = 100;

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
      else if(strcmp(argv[ii],"sloth")==0){
        usesloth=true;
        percentile=atof(argv[++ii]);
      }
    }

    // Register default values of parameters.
    GAParameterList params;
    GASteadyStateGA::registerDefaultParameters(params);
    //GASimpleGA::registerDefaultParameters(params);
    params.set(gaNpopulationSize,pop); // Population size.
    params.set(gaNnGenerations,gen); // Number of generations.
    params.set(gaNpCrossover,0.95); // Probability of crossover.
    params.set(gaNpMutation,0.05); // Probability of mutation.
    //params.set(gaNpReplacement,1.0); // Replacement strategy for steady-state GA
    params.set(gaNnReplacement,pop); // Replacement strategy for steady-state GA
    params.set(gaNscoreFrequency,1); // How often to record scores.
    params.set(gaNflushFrequency,1); // How often to dump scores to file.
    params.set(gaNrecordDiversity,gaTrue); // Record diversity
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
   /* if(!effectiveXO){
      std::cout << "Using one point crossover." << std::endl;
      genome.crossover(GEListGenome::OnePointCrossover);
    }
    else{
      std::cout << "Using effective crossover." << std::endl;
      genome.crossover(GEListGenome::effCrossover);
    }
    */
    
    //Use Custom Crossover
    std::cout << "Using Custom crossover." << std::endl;
    genome.crossover(CustomCrossover);

    //Use our point-mutation.
    genome.mutator(GEListGenome::pointMutator);
    
    //Initialise libGE mapper.
    app_init(wrappingEvents,grammarFile);
    
    // Create GA with a steady-state approach.
    GASteadyStateGAMulti ga(genome);
    //GASimpleGA ga(genome);
    
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
    
    // Sets the Selection Method
    GATournamentSelector selector;
    ga.selector(selector);

    // Stats file.
    ofstream stats("log/statistics.log");
    
    // Apply all settings to ga, including random seed
    ga.initialize(seed);

    // Print out garan2 to see that the random seed is the same up to this point
    cout << "Random Seed: " << GAGetRandomSeed() << endl;
    
    // Initialize Shiny app
    if(runapp){
    system("sh runapp.sh &");
    }
    
    
    // Evolutionary cycle
    int j=0;
    
    // PID parameters
    //double initial, setpoint, current_diversity = 0.0;
    
    cout << "Generations: ";
    while(!ga.done()){
      
      // Save sloth configs
      if(usesloth==true && j==0){
        std::ofstream outFile("tmp/sloth");
        outFile << percentile << "\n";
      }
      
      //Evolutionary Step Here
      ga.step();
      
      // Initialize PID controller for sloth
      //PID pid = PID(1, 0.1, 0.0, 0.01, 0.001, 0.5);
      
      if(usesloth==true){
        
       /* string str ="";
          
        ifstream input_file("tmp/current_diversity");
        if (!input_file.is_open()) {
          cerr << "Could not open the diversity file" << endl;
          exit(EXIT_FAILURE);
        }else{
        str = string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
        }
        
        if(j==0){
          
          initial = stof(str);
          current_diversity = initial;
          cout << "Initial diversity: " << initial << endl;
         
        }
        else{
          current_diversity = stof(str);
          cout << "Current diversity: " << current_diversity << endl;
        }
        
        setpoint = 0.2*initial;
        cout << "Setpoint: " << setpoint << endl;
        
        double control_action = pid.calculate(setpoint, current_diversity);
        
        cout << "Control action: " << control_action << endl;
        
        percentile += control_action;
        
      */
        
        std::ofstream outFile("tmp/sloth");
        outFile << percentile << "\n";
      }
      
      
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
    
    // Print out garan2 to see that the random seed is the same up to this point
    cout << "Random Seed: " << GAGetRandomSeed() << endl;
    
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
    
    // Killing R sessions 
    //system("for pid in $(ps -ef | awk '/shiny/ {print $2}'); do kill -9 $pid; done");
    
    return 0;
}


/* ---- Allow crossover only on effective length of individuals ---- */
int CustomCrossover (const GAGenome &p1, const GAGenome &p2,  GAGenome *c1, GAGenome *c2)
{
  
  //Casting from GAGenome to GEListGenome won't bring an effective size?
  //Possible reason for mom.getEffectiveSize() always returning 0 as answer
  
  const GEListGenome &mom = static_cast <const GEListGenome &> (p1);
  const GEListGenome &dad = static_cast <const GEListGenome &> (p2);
  
 cout << "Mom: " << endl;
 print_genotype(mom);
 cout << "\n";
 
 cout << "Dad: " << endl;
 print_genotype(dad);
 cout << "\n";
 
  //cout << "Random Seed: " << GAGetRandomSeed() << endl; 
  srand(GAGetRandomSeed());
 
  mapper.setGenotype(mom);
  int ef_size_m = mapper.getGenotype()->getEffectiveSize();
  int size_m = mom.size();
  
  mapper.setGenotype(dad);
  int ef_size_d = mapper.getGenotype()->getEffectiveSize();
  int size_d = dad.size();
  
  //cout << "Ef mom size:" << ef_size_m << endl;
  //cout << "Mom size:" << size_m << endl;
  //cout << "Ef dad size:" << ef_size_d << endl;
  //cout << "Dad size:" << size_d << endl;
  
  int nc = 0;
  int a, b; // Crossover points

  if (ef_size_m > size_m)
  {
		// Wrapping was used, choose random location
		//a = GARandomInt(0, mom.size());
		 		
		a = (rand() % (size_m + 1));
		
		cout << "Point a: " << a << endl;
	}
	else
	{
		// Choose point from effective length
		//a = GARandomInt(0, mom.getEffectiveSize());
		
		a = (rand() % (ef_size_m + 1));
		
		cout << "Point a: " << a << endl;
	}

 if (ef_size_d > size_d)
 {
		// Wrapping was used, choose random location
		//b = GARandomInt(0,dad.size());
		
		b = (rand() % (size_d + 1));
		
		cout << "Point b: " << b << endl;
	}
	else
	{
		// Choose point from effective length
		//b = GARandomInt(0, dad.getEffectiveSize());
		b = (rand() % (ef_size_d + 1));
		
		cout << "Point b: " << b << endl;
	}

	GAList <unsigned char> * list;

	if (c1)
	{
		GAListGenome <unsigned char> &sis = static_cast <GAListGenome <unsigned char> &> (*c1);
		sis.GAList <unsigned char> :: copy(mom);
		list = dad.GAList<unsigned char>::clone(b);
		if (a < mom.size() && a != 0)
		{
			unsigned char *site = sis.warp(a);
			while (sis.tail() != site)
			{
				sis.destroy();		// delete the tail node
			}
			sis.destroy();		// trash the trailing node (list[a])
		}
		else
		{
			sis.tail();		// move to the end of the list
		}
		sis.insert (list);		// stick the clone onto the end
		delete list;
		sis.head();			// set iterator to head of list
		nc += 1;
		
		cout << "Child 1: " << endl;
		print_genotype(sis);
		cout << "\n";
	}

	if (c2)
	{
		GAListGenome <unsigned char> &bro = static_cast <GAListGenome<unsigned char> &> (*c2);
		bro.GAList <unsigned char> :: copy (dad);
		list = mom.GAList <unsigned char> :: clone(a);
		if (b < dad.size() && b != 0)
		{
			unsigned char *site = bro.warp(b);
			while (bro.tail() != site)
			{
				bro.destroy();	// delete the tail node
			}
			bro.destroy();	// trash the trailing node (list[a])
		}
		else
		{
			bro.tail();	// move to the end of the list
		}
		bro.insert(list);	// stick the clone onto the end
		delete list;
		bro.head();	// set iterator to head of list
		nc += 1;
		
		cout << "Child 2: " << endl;
		print_genotype(bro);
		cout << "\n";
	
	}
	
	cout << "=================" << endl;
	
	return nc;
	
	
}

#endif

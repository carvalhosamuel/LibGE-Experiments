#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <ga/ga.h>
#include <GE/ge.h>

using namespace std;

// GE mapper, declared in main.cpp
extern GEGrammarSI mapper;

//Buffers for start and end code of the individual.c file
string SPstart("");
string SPend("");

//Loads the start and end code required to compile phenotypes,
//and initialises the mapper
void app_init(unsigned int wrappingEvents, string grammarFile){
  /* Init GE mapper */
	//Set maximum number of wrapping events per mapping
	mapper.setMaxWraps(wrappingEvents);
	//Load grammar
	if (!mapper.readBNFFile(grammarFile)){
	        cerr << "Could not read "<< grammarFile << "\n";
		cerr << "Execution aborted.\n";
		exit(0);
	}

	char buffer[1000];
	FILE *c_code;

	/* Read buffer code files */
	if(!(c_code=fopen("template/individual_start.sv","r"))){
		cerr << "Could not read template/individual_start.sv\n";
		cerr << "Execution aborted.\n";
		exit(0);
	}
	while(fgets(buffer,1000,c_code))
                  SPstart.append(buffer);
	fclose(c_code);

	if(!(c_code=fopen("template/individual_end.sv","r"))){
		cerr << "Could not read template/individual_end.sv\n";
		cerr << "Execution aborted.\n";
		exit(0);
	}
	while(fgets(buffer,1000,c_code))
                  SPend.append(buffer);
	fclose(c_code);
  }

//Attributes a fitness score to a genome
float objfunc(GAGenome &g) {
  GEListGenome &genome = static_cast<GEListGenome&>(g);
	//Assign genotype to mapper
	mapper.setGenotype(genome);
	//Grab phenotype
  Phenotype const *phenotype=mapper.getPhenotype();
	if(phenotype->getValid())
	  {
		FILE *file;
		int fitness;

		//Create output file
		if(!(file=fopen("tmp/individual.sv","w")))
		  {
		    cerr << "Could not open tmp/individual.cpp.\n";
		    cerr << "Execution aborted.\n";
		    exit(0);
		  }
		//Write start buffer to file
		fprintf(file,"%s",SPstart.c_str());
		//Write phenotype code to file
		fprintf(file,"%s",phenotype->getString().c_str());

		//Write end buffer to file
		fprintf(file,"%s",SPend.c_str());
		fclose(file);

		if(system("echo 0 > tmp/result && iverilog -g2009 -o tmp/a.out src/testbench.sv \
              && tmp/a.out > tmp/result") == -1)
		//Compile and execute file with GCC
		  {
		    cerr << "Compilation or execution failed.\n";
		    cerr << "Execution aborted.\n";
		    exit(0);
		  }

		//Open result file, containing fitness score
		if(!(file=fopen("tmp/result","r")))
		  {
		    cerr << "Could not open result file.\n";
		    cerr << "Execution aborted.\n";
		    exit(0);
		  }
	    	
		// read fitness
		int count=fscanf(file,"%d",&fitness);
	      	if (count < 1){
			puts("Unexpected error in input data.");
			exit(EXIT_FAILURE);
	    	}
		fclose(file);

		if(isinf(fitness) || isnan(fitness) || !isfinite(fitness))
		  fitness = 0;
		// cout << *phenotype << " (" << fitness << ")\n";

		// Set effective size of genome
		genome.setEffectiveSize(mapper.getGenotype()->getEffectiveSize());

		return fitness;
	  }
	else
	  return 0;
}

//Print an individual to stdout
void print_individual(const GAGenome &g)
{
	GAListGenome<unsigned char> &genome =
		(GAListGenome<unsigned char> &) g;
	//Assign genotype to mapper
	mapper.setGenotype(genome);
	cout << "Best individual:\n";
	//Print phenotype
	cout << *(mapper.getPhenotype());
	cout << endl;
	cout << "Genotype = " << *mapper.getGenotype() << "\n";
	cout << "Total length     = "
		<< mapper.getGenotype()->size() << "\n";
	cout << "Effective length = "
		<< mapper.getGenotype()->getEffectiveSize() << "\n";
	cout << "Wrapping events = "
		<< mapper.getGenotype()->getWraps() << "\n";
}


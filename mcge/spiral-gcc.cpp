#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/mman.h>

#include <GE/ge.h>
#include <ga/ga.h>

using namespace std;

// GE mapper, declared in main.cpp
extern GEGrammarSI mapper;

// Buffers for start and end code of the individual.c file
static string SPstart("");
static string SPend("");

// Loads the start and end code required to compile phenotypes,
// and initialises the mapper
void app_init(unsigned int wrappingEvents, string grammarFile) {

  /* Init GE mapper */
  // Set maximum number of wrapping events per mapping
  mapper.setMaxWraps(wrappingEvents);
  // Load grammar
  if (!mapper.readBNFFile(grammarFile)) {
    cerr << "Could not read " << grammarFile << "\n";
    cerr << "Execution aborted.\n";
    exit(0);
  }

  char buffer[1000];
  FILE *c_code;

  /* Read buffer code files */
  if (!(c_code = fopen("spiralstart.c", "r"))) {
    cerr << "Could not read spiralstart.c\n";
    cerr << "Execution aborted.\n";
    exit(0);
  }
  while (fgets(buffer, 1000, c_code))
    SPstart.append(buffer);
  fclose(c_code);

  if (!(c_code = fopen("spiralend.c", "r"))) {
    cerr << "Could not read spiralend.c\n";
    cerr << "Execution aborted.\n";
    exit(0);
  }
  while (fgets(buffer, 1000, c_code))
    SPend.append(buffer);
  fclose(c_code);
}

//// Attributes a fitness score to a genome
//float objfunc(GAGenome &g) {
//  GEListGenome &genome = static_cast<GEListGenome &>(g);
//  // Assign genotype to mapper
//  mapper.setGenotype(genome);
//  // Grab phenotype
//  Phenotype const *phenotype = mapper.getPhenotype();
//  if (phenotype->getValid()) {
//    FILE *file;
//    int fitness;
//
//    // Create output file
//    if (!(file = fopen("individual.c", "w"))) {
//      cerr << "Could not open individual.c.\n";
//      cerr << "Execution aborted.\n";
//      exit(0);
//    }
//    // Write start buffer to file
//    fprintf(file, "%s", SPstart.c_str());
//    // Write phenotype code to file
//    fprintf(file, "%s", phenotype->getString().c_str());
//
//    // Write end buffer to file
//    fprintf(file, "%s", SPend.c_str());
//    fclose(file);
//
//  cout << "Genotype = " << *mapper.getGenotype() << "\n";
//    // Compile and execute file with GCC
//    if (system("gcc -pipe individual.c gcc_GEspiral.o -lm\
//				&& ./a.out > result") == -1) {
//      cerr << "Compilation or execution failed.\n";
//      cerr << "Execution aborted.\n";
//      exit(0);
//    }
//
//    // Open result file, containing fitness score
//    if (!(file = fopen("result", "r"))) {
//      cerr << "Could not open result file.\n";
//      cerr << "Execution aborted.\n";
//      exit(0);
//    }
//    // read fitness
//    int count = fscanf(file, "%d", &fitness);
//    if (count < 1) {
//      puts("Unexpected error in input data.");
//      exit(EXIT_FAILURE);
//    }
//    fclose(file);
//
//    if (isinf(fitness) || isnan(fitness) || !isfinite(fitness))
//      fitness = 0;
//    // cout << *phenotype << " (" << fitness << ")\n";
//
//    // Set effective size of genome
//    genome.setEffectiveSize(mapper.getGenotype()->getEffectiveSize());
//
//    return fitness;
//  } else
//    return 0;
//}

// Attributes a fitness score to a genome
float objfunc(GAGenome &g) {
  GEListGenome &genome = static_cast<GEListGenome &>(g);
  // Assign genotype to mapper
  mapper.setGenotype(genome);
  // Grab phenotype
  Phenotype const *phenotype = mapper.getPhenotype();
  
  if (phenotype->getValid()) {
    unsigned fitness;

    unsigned long long t[] = { 0x69, 0x17 };// 1-bit full-adder {sum_out, carry_out}
    unsigned long long v[] = { 0x0f, 0x33, 0x55 };// 3-input truth table
    static char *hexstring = (char *)malloc(4096 * sizeof(char));
    char *pos = hexstring;
    strcpy(hexstring, phenotype->getString().c_str());
    const char* d = hexstring;
    // Remove white spaces coming from the grammar reading.
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*hexstring++ = *d++);
    hexstring = pos;

    static unsigned char *prog = (unsigned char*)mmap(0, 1024, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
    for (size_t i = 0; i < strlen(hexstring); i++) {
            sscanf(pos, "%2hhx", &prog[i]);
            pos += 2;
    }
    //printf("\n\nBefore run:\nv0 = %llx\tv1 = %llx\tv2 = %llx\n", v[0], v[1], v[2]);
    typedef void(*pFunction)(unsigned long long *);
    ((pFunction)prog)(v);
    
    //printf("After run: \nv0 = %llx\tv1 = %llx\tv2 = %llx\n", v[0], v[1], v[2]);
    
    v[0] &= 0xff; 
    v[1] &= 0xff; // v[1] = v[1] AND 0xff bitwisely
     
    //printf("After masking:\nv0 = %llx\tv1 = %llx\tv2 = %llx\n", v[0], v[1], v[2]);

    //printf("After XORing: ");
    fitness = 0;
    
    // Fitness is obtained by XORing the result from the individual with the truth table.
    // If they differ, XOR will be 1. As we are minising fitness, every time they differ the
    // fitness score increases.
    
    for (int i = 0; i < 2; i++) {
		v[i] ^= t[i];   // v[i] = v[i] XOR t[i] bitwisely
		//printf("v = %llx\t", v[i]);
		fitness += __builtin_popcountll(v[i]); //Returns the number of 1-bits in v[i]
	} //printf("\n");

    //cout << "Genotype  = " << *mapper.getGenotype() << "\n";
    cout << "Phenotype = " << *phenotype << " (" << fitness << ")\n\n";

    // Set effective size of genome
    genome.setEffectiveSize(mapper.getGenotype()->getEffectiveSize());
    

    return (float)fitness;
  } else {
    //cout << "Invalid!\n";
    return 9999.9;
  }
}

// Print an individual to stdout
void print_individual(const GAGenome &g) {
  GAListGenome<unsigned char> &genome = (GAListGenome<unsigned char> &)g;
  // Assign genotype to mapper
  mapper.setGenotype(genome);
  cout << "Best individual:\n";
  // Print phenotype
  cout << *(mapper.getPhenotype());
  cout << endl;
  cout << "Genotype = " << *mapper.getGenotype() << "\n";
  cout << "Total length     = " << mapper.getGenotype()->size() << "\n";
  cout << "Effective length = " << mapper.getGenotype()->getEffectiveSize()
       << "\n";
  cout << "Wrapping events = " << mapper.getGenotype()->getWraps() << "\n";
  cout << "Fitness = " << mapper.getGenotype()->getFitness() << "\n";
}

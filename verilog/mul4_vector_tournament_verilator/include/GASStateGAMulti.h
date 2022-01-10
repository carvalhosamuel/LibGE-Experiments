#include <ga/ga.h>
#include <ga/GAPopulation.h>

#ifndef _ga_gasteadystatemulti_h_
#define _ga_gasteadystatemulti_h_

class GASteadyStateGAMulti : public GASteadyStateGA {
  public:
    GASteadyStateGAMulti(const GAGenome &genome) : GASteadyStateGA(genome){};
    GASteadyStateGAMulti(const GAPopulation &pop) : GASteadyStateGA(pop){};
    GASteadyStateGAMulti(const GASteadyStateGA &ga) : GASteadyStateGA(ga){};
  
  public:
    void setInitializer(GAPopulation::Initializer i){
      pop->initializer(i);
      tmpPop->initializer(i);
    }

    void setEvaluator(GAPopulation::Evaluator e){
      pop->evaluator(e);
      tmpPop->evaluator(e);
    }
};
#endif

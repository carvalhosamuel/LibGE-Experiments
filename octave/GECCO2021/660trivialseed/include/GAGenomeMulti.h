#include <ga/ga.h>
#include <ga/GAGenome.h>

#ifndef _ga_gagenomemulti_h_
#define _ga_gagenomemulti_h_
class GAGenomeMulti : public GAGenome {
  public:
      GABoolean getEvaluated(){
        return _evaluated;
      }
      
      void setEvaluated(GABoolean flag){
		 _evaluated = flag;
	  }
};
#endif

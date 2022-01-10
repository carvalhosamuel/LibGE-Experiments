#include <stdio.h>

typedef double Real;

void initCart();
void resetCart();
// void stepCart(); //deprecated
void stepSim();

Real DIV(Real n, Real d);
Real GT(Real lhs, Real rhs);
Real ABS(Real x);

extern Real X;
extern Real V;
extern Real velocityChange;
extern Real posForceVelChange;
extern Real negForceVelChange;
extern Real sumFitCaseTimes;
extern unsigned int hitCount;
extern unsigned int numFitCase;
extern unsigned int currFitCase;

int main(void) {
  initCart();
  resetCart();
  while (currFitCase < numFitCase) {
    if (
X
    > 0.0)
    {
      velocityChange = posForceVelChange;
    }
    else {
      velocityChange = negForceVelChange;
    }

    stepSim();
    }

    printf("%f %d\n", sumFitCaseTimes, hitCount);

    return (0);
    }

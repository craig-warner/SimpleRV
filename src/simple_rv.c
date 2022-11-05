/*
 * Summation
*
 */
#include "simple_rv.h"

/*
 * Globals
 */

#ifdef SPIKE
volatile long unsigned int64Sum;
volatile double doubleSum;
volatile float floatSum;
#endif

long unsigned uint64Array[NUM_UINT64_ELEMENTS] = {1ull,2ull,3ull,4ull,5ull,6ull,7ull,8ull,9ull,10ull};
double doubleArray[NUM_DOUBLE_ELEMENTS] = {0.1,0.4,0.1,3.1};
float floatArray[NUM_FLOAT_ELEMENTS] = {0.7,0.04};

/*
 * Functions
 */

int main() {
  unsigned i;
  long unsigned iSum; 
  double dSum; 
  float fSum; 

  // uint64_t sum
  iSum = 0;
  for(i=0;i<NUM_UINT64_ELEMENTS;i++) {
    iSum += uint64Array[i];
  }
#ifdef SPIKE
    int64Sum = iSum;
#else
    //printf ("Sum of Array %ld",isum);
#endif //SPIKE

  // float sum
  fSum = 0;
  for(i=0;i<NUM_FLOAT_ELEMENTS;i++) {
    fSum += floatArray[i];
  }
#ifdef SPIKE
    floatSum = fSum;
#else
    //printf ("Sum of Array %f",fsum);
#endif //SPIKE

  // double sum
  dSum = 0;
  for(i=0;i<NUM_DOUBLE_ELEMENTS;i++) {
    dSum += doubleArray[i];
  }
#ifdef SPIKE
    doubleSum = dSum;
#else
    //printf ("Sum of Array %f",dsum);
#endif //SPIKE

}
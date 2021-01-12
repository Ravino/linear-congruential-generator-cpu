#include <vector>
#include "worker.h"
#include "generator.h"


void worker(std::vector<unsigned> *&vec, firstValueStruct firstValue, std::size_t itemFlow, unsigned countFlow, unsigned length) {


//  double currentMiddleValue = 0.0;


  unsigned x = firstValue.x;
  unsigned lastA = firstValue.lastA;
  unsigned b = firstValue.b;
  unsigned min = firstValue.min;
  unsigned max = firstValue.max;


  for (size_t i = itemFlow; i < length; i += countFlow) {
    vec -> at(i) = (x % (max - min)) + min;
//    currentMiddleValue += (double) vec -> at(i);
    x = createGenerator(x, firstValue.lastA, firstValue.b);
  }



//  mtx.lock();
//  middleValue[itemFlow] += currentMiddleValue;
//  mtx.unlock();
}

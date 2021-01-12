#include <vector>
#include "worker.h"
#include "generator.h"


void worker(unsigned *vec, firstValueStruct firstValue, std::size_t itemFlow, unsigned countFlow, unsigned length, std::mutex& mtx, double& shared_average) {


//  double currentMiddleValue = 0.0;


  unsigned x = firstValue.x;
  unsigned lastA = firstValue.lastA;
  unsigned b = firstValue.b;
  unsigned min = firstValue.min;
  unsigned max = firstValue.max;
  double my_sum = 0.0;


  for (size_t i = itemFlow; i < length; i += countFlow) {
    vec[i] = (x % (max - min)) + min;
    my_sum += vec[i];
//    currentMiddleValue += (double) vec -> at(i);
    x = createGenerator(x, firstValue.lastA, firstValue.b);

  }
  mtx.lock();
  shared_average += my_sum;
  mtx.unlock();


//  mtx.lock();
//  middleValue[itemFlow] += currentMiddleValue;
//  mtx.unlock();
}

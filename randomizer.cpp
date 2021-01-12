#include <vector>
#include <thread>
#include <ctime>
#include <mutex>
#include "randomizer.h"
#include "flow.h"
#include "generator.h"
#include "worker.h"




double randomize_cpu(unsigned *vec, unsigned length, unsigned min, unsigned max) {

  double middleValue = 0.0;
  unsigned countFlow = getCountFlow();


  std::mutex mtx;


    std::vector<firstValueStruct> firstValueVec = createFirstValue(countFlow, min, max);
  std::vector<std::thread> poolFlow = createPoolFlow(countFlow);


  for (std::size_t itemFlow = 0; itemFlow < countFlow; ++itemFlow) {
    poolFlow.emplace_back(std::thread(worker, vec, firstValueVec[itemFlow], itemFlow, countFlow, length, std::ref(mtx), std::ref(middleValue)));
  }


  for(std::thread &flow: poolFlow) {
    flow.join();
  }


  return middleValue / length;
}

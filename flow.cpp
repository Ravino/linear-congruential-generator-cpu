#include <vector>
#include <thread>
#include "flow.h"


unsigned getCountFlow() {
  unsigned countFlow = std::thread::hardware_concurrency();
  return countFlow;
}


std::vector<std::thread> createPoolFlow(unsigned countFlow) {
  std::vector<std::thread> poolFlow;
  poolFlow.reserve(countFlow);
  return poolFlow;
}

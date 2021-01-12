#include <vector>
#include "generator.h"
#include <mutex>


void worker(unsigned *vec, firstValueStruct firstValue, std::size_t itemFlow, unsigned countFlow, unsigned length, std::mutex& mtx, double& shared_average);

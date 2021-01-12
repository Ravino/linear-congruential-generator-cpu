#include <vector>
#include <ctime>
#include "generator.h"


#define A 1103515245u
#define B 12345u
#define C 4294967296u


std::vector<firstValueStruct> createFirstValue(unsigned countFlow, unsigned min, unsigned max) {

  unsigned seed = std::time(nullptr);



  firstValueStruct firstValue;
  firstValue.a = A;


  std::vector<firstValueStruct> vec;


  vec.reserve(countFlow);
  vec.emplace_back(firstValue);


  for(unsigned i = 1; i < countFlow + 1; i++) {

    firstValueStruct currentFirstValue = vec[i-1];


    unsigned currentMultiplier = currentFirstValue.a;
    unsigned lastMultiplier = (currentMultiplier * A) % C;


    firstValueStruct firstValue;
    firstValue.a = lastMultiplier;


    vec[i] = firstValue;
  }


  unsigned lastA = vec.back().a;


  for(unsigned i; i < vec.size(); i++) {
    vec[i].lastA = lastA;
    vec[i].min = min;
    vec[i].max = max;
    vec[i].b = (B * (lastA - 1) / (A - 1)) % C;
    vec[i].x = ((seed * vec[i].a) % C + (B * (vec[i].a - 1) / (A - 1)) % C) % C;
  }


  return vec;
}




unsigned createGenerator(unsigned x, unsigned lastA, unsigned b) {
  x = ((x * lastA) % C + b) % C;
  return x;
}

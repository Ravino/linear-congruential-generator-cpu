#pragma once


#include <vector>


struct firstValueStruct {
  unsigned a;
  unsigned b;
  unsigned x;
  unsigned lastA;
  unsigned min;
  unsigned max;
};


std::vector<firstValueStruct> createFirstValue(unsigned countFlow, unsigned min, unsigned max);


unsigned createGenerator(unsigned x, unsigned lastA, unsigned b);

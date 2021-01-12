#include <vector>
#include "randomizer.h"
#include <iostream>



int main () {

  unsigned length = 1000;


  unsigned *vec = new unsigned[length];
  /*
  equivalently:
  1. std::vector<unsigned> vec(length);
  2. auto vec = std::make_unique<unsigned[]>(length);
  */


  double result = randomize_cpu(vec, length, 10, 100);
  std::cout << result << '\n';

  /*
  1. double result = randomizer(vec.data(), length, 10, 100);
  2. double result = randomizer(vec.get(), length, 10, 100);
  */

  delete [] vec;

  return 0;
}

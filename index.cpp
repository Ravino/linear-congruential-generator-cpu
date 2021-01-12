#include <vector>
#include "randomizer.h"




int main () {

  unsigned length = 1000;


  std::vector<unsigned> *vec = new std::vector<unsigned>[length];
  vec -> reserve (length);


  double result = randomizer(vec, length, 10, 100);


  return 0;
}

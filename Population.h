
#ifndef _POPULATION_H_
#define _POPULATION_H_

#include "Individual.h"
#include <vector>
#include <algorithm>

class Population {
public:
  Population() 
    : indvs(100)
  {}

  Population(int size) 
    : indvs(size)
  {}


private:
  std::vector<Individual> indvs;



};




#endif
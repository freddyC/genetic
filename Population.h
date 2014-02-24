
#ifndef _POPULATION_H_
#define _POPULATION_H_

#include "Individual.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>

const int POPULATION_SIZE = 100;
class Population {
public:
  Population()
    : people(POPULATION_SIZE)
  {
    std::generate(people.begin(), people.end(), [&] () {
      std::shared_ptr<Individual> temp(new Individual);
      return temp;
    });
  }


  void print();

private:

  std::vector<std::shared_ptr<Individual> > people;


};

#endif
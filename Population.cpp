#include "Population.h"

void Population::print() {
  std::for_each(people.begin(), people.end(), [&] (std::shared_ptr<Individual> ind) {
    ind->print();
  });
}


#include "Population.h"

void Population::print() {
  std::pair<double, double> cord;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(-3, 3);

  cord.first = dis(gen);
  cord.second = dis(gen);
  std::for_each(people.begin(), people.end(), [&] (std::shared_ptr<Individual> ind) {
    ind->printCord(cord);
  });
}


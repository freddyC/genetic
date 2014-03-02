
#ifndef _POPULATION_H_
#define _POPULATION_H_

#include "Individual.h"
#include "Analyze.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>

const int POPULATION_SIZE = 100;

class Population {
public:
  Population()
    : people(POPULATION_SIZE)
    , analyzer(std::make_shared<Analyze>())
  {
    analyzer->analyzeTrainingPointsFile();
    std::generate(people.begin(), people.end(), [&] () {
      return std::make_shared<Individual>(analyzer);
    });
  }

  std::vector<char> migrationGet ();
  void migrationSet (std::vector<char>);

  void print ();
  void cull ();
  void repopulate ();
  std::shared_ptr<Individual> getBest ();
  int size() { return people.size(); }

private:

  std::pair<std::vector<char>, int> getRandomFather ();

  std::vector<std::shared_ptr<Individual> > people;
  std::shared_ptr<Analyze> analyzer;


};

#endif
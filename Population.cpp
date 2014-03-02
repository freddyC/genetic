#include "Population.h"

void Population::print (void) {
  std::for_each(people.begin(), people.end(), [&] (std::shared_ptr<Individual> ind) {
    ind->print();
  });
}

void Population::cull (void) {
  // a 10% chance the less score stayes alive
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0, 1);
  for (int i = 0; i < people.size(); i+=2) {
    auto chance = dis(gen);
    if (chance < 0.9) {
      (people[i]->score > people[i+1]->score) ? people[i+1] = NULL : people[i] = NULL;
    } else {
      (people[i]->score < people[i+1]->score) ? people[i+1] = NULL : people[i] = NULL;
    }
  }
}

void Population::repopulate (void) {
  for (int i = 0; i < people.size(); i+=2) {
    if (people[i] == NULL) {
      auto temp = people[i+1]->mutation();
      people[i] = std::make_shared<Individual>(analyzer, temp);
    } else {
      auto temp = people[i]->mutation();
      people[i+1] = std::make_shared<Individual>(analyzer, temp);
    }
  }
}
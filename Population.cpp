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
    auto fatherPair = getRandomFather();
    if (people[i] == NULL) {
      auto opers = people[i+1]->generatePerson(fatherPair.first, fatherPair.second);
      people[i] = std::make_shared<Individual>(analyzer, opers);
    } else {
      auto opers = people[i]->generatePerson(fatherPair.first, fatherPair.second);
      people[i+1] = std::make_shared<Individual>(analyzer, opers);
    }
  }
}

std::shared_ptr<Individual> Population::getBest () {
  int bestI = 0
    , bestScore = 0
    ;

  for (int i = 0; i < people.size(); ++i) {
    if (people[i]->score > bestScore) {
      bestI = i;
      bestScore = people[i]->score;
    }
  }
  return people[bestI];
}

std::pair<std::vector<char>, int> Population::getRandomFather () {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, people.size() -1);
  bool isNull = true;
  std::vector<char> fatherOpers;
  int fatherScore;

  while (isNull) {
    int i = dis(gen);
    if (people[i] != NULL) {
      isNull = false;
      fatherOpers = people[i]->getOperations();
      fatherScore = people[i]->score;
    }
  }

  return std::pair<std::vector<char>, int> (fatherOpers, fatherScore);
}

std::vector<char> Population::migrationGet () {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, people.size() -1);
  bool isNull = true;
  std::vector<char> person;

  while (isNull) {
    int i = dis(gen);
    if (people[i] != NULL) {
      isNull = false;
      person = people[i]->getOperations();
      people[i] = NULL;
    }
  }

  return person;
}


void Population::migrationSet (std::vector<char> opers) {
  for (int i = 0; i < people.size(); ++i) {
    if (people[i] == NULL) {
      people[i] = std::make_shared<Individual>(analyzer, opers);
      i = people.size();
    }
  }
}
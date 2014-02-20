

#ifndef _INDIVIDUAL_H_
#define _INDIVIDUAL_H_

#include <random>

class Individual {
public:

  Individual() {
    this->value = this->rand();
  }

private:
  int rand() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 5000);
    return dis(gen);
  } // http://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution

  int value;

};

#endif
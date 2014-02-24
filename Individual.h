

#ifndef _INDIVIDUAL_H_
#define _INDIVIDUAL_H_
#include <random>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

const int OPERATIONS_LENGTH = 100;

class Individual {
public:

  Individual()
    : operations(OPERATIONS_LENGTH)
  {
    std::generate(operations.begin(), operations.end(), [&] () {
      return getRandomFunction();
    });
  }

  std::vector<char> const getOperations () {
    return operations;
  }

  void setOperations (std::vector<char> v) {
    if (v.size() != OPERATIONS_LENGTH) return;
    for (int i = 0; i < OPERATIONS_LENGTH; ++i) {
      operations[i] = v[i];
    }
  }

  void print();
  void printCord(std::pair<double, double> &cord);

private:
  void act(char action, std::pair<double, double> &val);
  char getRandomFunction();



  std::vector<char> operations;

  // Arithmatic functions: If x is
  void multiply_x (std::pair<double, double> &val);
  void multiply_y (std::pair<double, double> &val);

  void divide_x (std::pair<double, double> &val);
  void divide_y (std::pair<double, double> &val);

  void add_x (std::pair<double, double> &val);
  void add_y (std::pair<double, double> &val);

  void sub_x (std::pair<double, double> &val);
  void sub_y (std::pair<double, double> &val);

  void sine_x (std::pair<double, double> &val);
  void sine_y (std::pair<double, double> &val);

  void cosine_x (std::pair<double, double> &val);
  void cosine_y (std::pair<double, double> &val);

  void tan_x (std::pair<double, double> &val);
  void tan_y (std::pair<double, double> &val);

  void mod_x (std::pair<double, double> &val);
  void mod_y (std::pair<double, double> &val);

  void power_x (std::pair<double, double> &val);
  void power_y (std::pair<double, double> &val);

  void log_x (std::pair<double, double> &val);
  void log_y (std::pair<double, double> &val);

  void square_root_x (std::pair<double, double> &val);
  void square_root_y (std::pair<double, double> &val);

  void absoulte_value_x (std::pair<double, double> &val);
  void absoulte_value_y (std::pair<double, double> &val);
};
/*
  Capital is to X Lowercase is to Y
  Functions
  m = multiply
  d = divide
  a = add
  s = sub
  i = sine
  c = cosine
  t = tan
  r = mod (remainder)
  p = power
  l = log
  r = square root
  v = absoulte value
*/


#endif
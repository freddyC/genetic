

#ifndef _INDIVIDUAL_H_
#define _INDIVIDUAL_H_

#include "Analyze.h"
#include <random>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>


const int OPERATIONS_LENGTH = 100;
const int HEALTH_ITERATIONS = 100;

class Individual {
public:

  Individual(std::shared_ptr<Analyze> a);

  Individual(std::shared_ptr<Analyze> a, std::vector<char> actions);

  std::vector<char> const getOperations () { return operations; }

  void setOperations (std::vector<char> v);

  void calculateFitness ();
  void print ();
  std::vector<char> mutation ();
  int score;

private:
  void act(char action, std::pair<double, double> &val);
  char getRandomFunction();
  int timesInBuda(std::pair<double, double> cord);

  std::vector<char> operations;
  std::vector<char> funcs;
  std::shared_ptr<Analyze> analyzer;

  // Operations
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


#endif
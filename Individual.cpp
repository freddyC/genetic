
#include "Individual.h"

/*
  lowercase value performs operation to first (x)
  uppercase value performs operation to second (y)

  Possible Operations
  m = multiply
  d = divide
  a = add
  s = sub
  i = sine
  c = cosine
  t = tan
  o = mod
  p = power
  l = log
  r = square root
  v = absoulte value
*/
char Individual::getRandomFunction () {
  std::vector<char> funcs = {'m', 'd', 'a', 's', 'i', 'c', 't', 'o', 'p', 'l', 'r', 'v', 'M', 'D', 'A', 'S', 'I', 'C', 'T', 'O', 'P', 'L', 'R', 'V'};
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, funcs.size() -1);
  auto i = dis(gen);
  return funcs[i];
}

void Individual::print () {
  std::cout << "[\n";
  std::for_each(operations.begin(), operations.end(), [=] (char val) {
    std::cout << val << ", ";
  });
  std::cout << "\n]\n";
}

void Individual::printCord(std::pair<double, double> &cord) {
  std::cout << std::endl;
  std::for_each(operations.begin(), operations.end(), [&] (char val) {
    act(val, cord);
  });
  std::cout << " (" << cord.first << ", " << cord.second << ") ";
  std::cout << std::endl;
}

void Individual::act(char action, std::pair<double, double> &val) {
  std::cout << "\nAction = " << action << " pair before action (" << val.first << ", " << val.second << ")\n";
  switch(action) {
    case 'm':
      multiply_x(val);
      break;
    case 'M':
      multiply_y(val);
      break;
    case 'd':
      divide_x(val);
      break;
    case 'D':
      divide_y(val);
      break;
    case 'a':
      add_x(val);
      break;
    case 'A':
      add_y(val);
      break;
    case 's':
      sub_x(val);
      break;
    case 'S':
      sub_y(val);
      break;
    case 'i':
      sine_x(val);
      break;
    case 'I':
      sine_y(val);
      break;
    case 'c':
      cosine_x(val);
      break;
    case 'C':
      cosine_y(val);
      break;
    case 't':
      tan_x(val);
      break;
    case 'T':
      tan_y(val);
      break;
    case 'o':
      mod_x(val);
      break;
    case 'O':
      mod_y(val);
      break;
    case 'p':
      power_x(val);
      break;
    case 'P':
      power_y(val);
      break;
    case 'l':
      log_x(val);
      break;
    case 'L':
      log_y(val);
      break;
    case 'r':
      square_root_x(val);
      break;
    case 'R':
      square_root_y(val);
      break;
    case 'v':
      absoulte_value_x(val);
      break;
    case 'V':
      absoulte_value_y(val);
      break;
  }
  std::cout << "Val after Action (" << val.first << ", " << val.second << ")\n";
}

void Individual::multiply_x (std::pair<double, double> &val) {
  val.first = val.first * val.second;
}
void Individual::multiply_y (std::pair<double, double> &val) {
  val.second = val.first * val.second;
}


void Individual::divide_x (std::pair<double, double> &val) {
  val.first = val.first / val.second;
}
void Individual::divide_y (std::pair<double, double> &val) {
  val.second = val.second / val.first;
}


void Individual::add_x (std::pair<double, double> &val) {
  val.first = val.first + val.second;
}
void Individual::add_y (std::pair<double, double> &val) {
  val.second = val.second + val.first;
}


void Individual::sub_x (std::pair<double, double> &val) {
  val.first = val.first - val.second;
}
void Individual::sub_y (std::pair<double, double> &val) {
  val.second = val.second - val.first;
}


void Individual::sine_x (std::pair<double, double> &val) {
  val.first = std::sin(val.first);
}
void Individual::sine_y (std::pair<double, double> &val) {
  val.second = std::sin(val.second);
}


void Individual::cosine_x (std::pair<double, double> &val) {
  val.first = std::cos(val.first);
}
void Individual::cosine_y (std::pair<double, double> &val) {
  val.second = std::cos(val.second);
}


void Individual::tan_x (std::pair<double, double> &val) {
  val.first = std::tan(val.first);
}
void Individual::tan_y (std::pair<double, double> &val) {
  val.second = std::tan(val.second);
}


void Individual::mod_x (std::pair<double, double> &val) {
  val.first = std::fmod(val.first, val.second);
}
void Individual::mod_y (std::pair<double, double> &val) {
  val.second = std::fmod(val.second, val.first);
}


void Individual::power_x (std::pair<double, double> &val) {
  val.first = val.first * val.first;
}
void Individual::power_y (std::pair<double, double> &val) {
  val.second = val.second * val.second;
}


void Individual::log_x (std::pair<double, double> &val) {
  bool isNeg = false;
  if (val.first < 0) {
    isNeg = true;
  }
  val.first = std::log(std::abs(val.first));
  if (isNeg) {
    val.first *= -1;
  }
}
void Individual::log_y (std::pair<double, double> &val) {
  bool isNeg = false;
  if (val.first < 0) {
    isNeg = true;
  }
  val.second = std::log(std::abs(val.second));
  if (isNeg) {
    val.second *= -1;
  }
}


void Individual::square_root_x (std::pair<double, double> &val) {
  bool isNeg = false;
  if (val.first < 0) {
    isNeg = true;
  }
  val.first = std::sqrt(std::abs(val.first));
  if (isNeg) {
    val.first *= -1;
  }
}
void Individual::square_root_y (std::pair<double, double> &val) {
  bool isNeg = false;
  if (val.first < 0) {
    isNeg = true;
  }
  val.second = std::sqrt(std::abs(val.second));
  if (isNeg) {
    val.second *= -1;
  }
}


void Individual::absoulte_value_x (std::pair<double, double> &val) {
  val.first = std::abs(val.first);
}
void Individual::absoulte_value_y (std::pair<double, double> &val) {
  val.second = std::abs(val.second);
}


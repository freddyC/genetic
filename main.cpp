

#include "Population.h"

int main () {
  Population pop;

  for (int i = 0; i < 100; ++i) {
    pop.print();
    pop.cull();
    pop.repopulate();
  }


  return 0;
}
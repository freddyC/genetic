
#include "Population.h"
#include "Individual.h"
#include "Analyze.h"
#include <mpi.h>

int main(int argc, char * argv[]) {
  int proc_count, name;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &proc_count);
  MPI_Comm_rank(MPI_COMM_WORLD, &name);

  Population population;

  std::cout << "Node " << name << " started population of " << population.size() << " people.\n";

  for (int i = 0; i < 10000; ++i) {
    population.cull();
    population.repopulate();

    if (i % 100 == 0) {
      for (int i = 0; i < 100; ++i) {
        if (name % 2 == 0) {
          auto temp = population.migrationGet();
          std::vector<char> temp2;
          int size = temp.size();
          MPI_Send(&size, 1, MPI_INT, name +1, 0, MPI_COMM_WORLD);
          MPI_Send(&temp[0], size, MPI_UNSIGNED_CHAR, name +1, 0, MPI_COMM_WORLD);

          MPI_Recv(&size, 1, MPI_INT, name +1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
          MPI_Recv(&temp2[0], size, MPI_UNSIGNED_CHAR, name +1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
          population.migrationSet(temp2);

        } else {
          auto temp = population.migrationGet();
          std::vector<char> temp2;
          int size = 0;
          MPI_Recv(&size, 1, MPI_INT, name -1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
          MPI_Recv(&temp2[0], size, MPI_UNSIGNED_CHAR, name -1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

          size = temp.size();
          MPI_Send(&size, 1, MPI_INT, name -1, 0, MPI_COMM_WORLD);
          MPI_Send(&temp[0], size, MPI_UNSIGNED_CHAR, name -1, 0, MPI_COMM_WORLD);
          population.migrationSet(temp2);
        }
      }
    }
  }

  auto best = population.getBest();
  std::shared_ptr<Analyze> analyzer (std::make_shared<Analyze>());
  analyzer->analyzeTrainingPointsFile();
  Individual tester(analyzer, test);
  tester.calculateFitness();

  if(name == 0) {
    for (int i = 1; i < proc_count; ++i) {
      std::vector<char> temp;
      int size = 0;
      std::cout << "Recieceing best from Node " << i << std::endl;
      MPI_Recv(&size, 1, MPI_INT, name i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      MPI_Recv(&temp[0], size, MPI_UNSIGNED_CHAR, name i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

      Individual test2 (analyzer, temp);
      test2.calculateFitness();
      if (tester.score < test2.score) {
        tester = test2;
      }

      std::cout << "Recieved best from Node " << i << "\n\n";
    }
  } else {
    int size = best.size();
    MPI_Send(&size, 1, MPI_INT, name -1, 0, MPI_COMM_WORLD);
    MPI_Send(&best[0], size, MPI_UNSIGNED_CHAR, name -1, 0, MPI_COMM_WORLD);
  }


  Analyze reporter;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(-3, 3);

  for (int i = 0; i < 100000; ++i) {
    std::pair<double, double> cord;
    cord.first = dis(gen);
    cord.second = dis(gen);
    best->performActions(cord);
    reporter->addPoint(cord.first, cord.second);
  }

  a->writeGrid();
  return 0;
}

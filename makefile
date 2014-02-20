all: main.cpp Population.h Population.cpp Individual.h Individual.cpp
	g++ -std=c++11  main.cpp Population.cpp Individual.cpp -g -o run-gen
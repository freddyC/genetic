all: main.cpp Population.h Population.cpp Individual.h Individual.cpp Analyze.h Analyze.cpp
	g++ -std=c++11 main.cpp Population.cpp Individual.cpp Analyze.cpp -g -o run-gen
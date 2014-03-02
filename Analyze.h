#ifndef _ANALYZE_H_
#define _ANALYZE_H_

#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

class Analyze
{
public:
  Analyze()
  : grid()
  , x_min(-2.0)
  , y_min(-2.0)
  , x_max(2.0)
  , y_max(2.0)
  , height(480)
  , width(640)
  {
    grid.resize(width, std::vector<int> (height));
  }

  int analyzePoint (double x, double y);
  void analyzeTrainingPointsFile (void);
  void addPoint (double x, double y);

private:

  std::vector<std::vector <int> > grid;

  double  x_min
        , y_min
        , x_max
        , y_max
        ;

  int height
    , width
    ;

};

#endif
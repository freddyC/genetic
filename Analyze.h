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
  , max(0)
  , height(480)
  , width(640)
  {
    grid.resize(width, std::vector<int> (height));
  }

  int analyzePoint (double x, double y);
  void analyzeTrainingPointsFile ();
  void addPoint (double x, double y);
  void writeGrid ();

private:

  std::vector<std::vector <int> > grid;
  int get_r(double bias) { return (int)(((bias - 1 ) * (-1)) * 255 / 8); }
  int get_g(double bias) { return (int)(bias * 255 / 5); }
  int get_b(double bias) { return (int)(bias * 255); }
  
  double  x_min
        , y_min
        , x_max
        , y_max
        ;

  int max
    , height
    , width
    ;

};

#endif
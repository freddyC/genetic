#include "Analyze.h"

int Analyze::analyzePoint (double x, double y) {
  if( x <= x_min || y <= y_min || x >= x_max || y >= y_max) return 0;
  if (x != x || y != y) return 0;// check for NaN

  double x_percent = (x - x_min) / (x_max - x_min)
       , y_percent = (y - y_min) / (y_max - y_min)
       ;

  int x_pix = (int)(width * x_percent)
    , y_pix = (int)(height * y_percent)
    ;

  return grid[x_pix][y_pix] * grid[x_pix][y_pix];
}



void Analyze::analyzeTrainingPointsFile (void) {
  std::ifstream fin("/Users/fred.christensen/Dropbox/school/Parallel/genetic/points.txt");
  while (!fin.eof()) {
    double x
         , y
         ;

    fin >> x;
    fin >> y;
    addPoint(x, y);
  }
}


void Analyze::addPoint (double x, double y) {
  if ( x < x_min || y < y_min || x > x_max || y > y_max) return;
  if (x != x || y != y) return;

  double x_percent = (x - x_min) / (x_max - x_min)
       , y_percent = (y - y_min) / (y_max - y_min)
       ;

  int x_pix = (int)(width * x_percent)
    , y_pix = (int)(height * y_percent)
    ;

  ++grid[x_pix][y_pix];
  if (max < grid[x_pix][y_pix]) {
    max = grid[x_pix][y_pix];
  }
}

void Analyze::writeGrid () {
  std::ofstream fout ("/Users/fred.christensen/Dropbox/school/Parallel/genetic/result.ppm");
  fout << "P3\n640 420\n255\n";
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      double bias = (double)grid[x][y] / (double)max;
      fout << get_r(bias) << " " << get_g(bias) << " " << get_b(bias);
      if (x < width -1) {
        fout << "\t";
      } else {
        fout << std::endl;
      }
    }
  }
}

// leins, 15.04.2018

#include <vector>
#include <cmath>
#include "function.h"

using namespace std;

// generate x values
vector<double> BuildGrid(int numOfNodes)
{
  vector<double> x;
  double val = A;
  double h = (B - A) / numOfNodes;

  for (int i = 0; i <= numOfNodes; i++)
  {
    x.push_back(val + h * i);
  }

  return x;
}

double MyFunc(double x, double y, double z)
{
  return 1 - sin(x) - sin(x) * y - cos(x) * z;
}

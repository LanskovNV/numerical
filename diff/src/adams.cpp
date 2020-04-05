// leins,07.05.2018

#include <cmath>
#include "adams.h"

using namespace std;

vector<double> Adams(double y0, double numOfNodes)
{
  vector<double> x, y, z;
  double h = (B - A) / numOfNodes;
  double firstVal = 1;// + (y0 - Y0);
  x = BuildGrid(numOfNodes);

  y.push_back(y0);
  z.push_back(firstVal);
  y.push_back(y[0] + h * z[0]);
  z.push_back(z[0] + h * MyFunc(x[0], y[0], z[0]));

  for (int j = 2; j <= numOfNodes; j++)
  {
    double newYB = y[j - 1]
        + h / 2 * (3 * z[j - 1] - z[j - 2]);
    double newZB = z[j-1]
        +h/2*(3*MyFunc(x[j-1],y[j-1],z[j-1])-MyFunc(x[j-2],y[j-2],z[j-2]));
    double newZ = z[j-1]
        + h / 2 * (MyFunc(x[j], newYB, newZB) + MyFunc(x[j - 1], y[j-1], z[j-1]));
    double newY = y[j - 1]
        + h / 2 * (newZ + z[j - 1]);

    newY = newY - (newY - newYB)/ 2;
    newZ = newZ - (newZ - newZB)/ 2;

    z.push_back(newZ);
    y.push_back(newY);
  }

  return y;
}


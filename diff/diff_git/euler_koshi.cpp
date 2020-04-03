// leins, 16.04.2018

#include <cmath>
#include "euler_koshi.h"

using namespace std;

vector<double> EulerKoshi(double y0, double numOfNodes)
{
    const int kMax = 4;
    vector<double> x, y, z;
    double h = (B - A) / numOfNodes;

    x = BuildGrid(numOfNodes);
    double firstVal = 1;// + (y0 - Y0);

    y.clear();
    z.clear();
    y.push_back(y0);
    z.push_back(firstVal);

    for (int j = 1; j <= numOfNodes; j++)
    {
      double newY = y[j - 1] + h * z[j - 1];
      double newZ = z[j - 1] + h * MyFunc(x[j - 1], y[j-1], z[j-1]);

      z.push_back(newZ);
      y.push_back(newY);
      for (int i = 0; i < kMax; i++)
      {
        newY = y[j - 1] + h / 2 * (z[j-1] + z[j]);
        newZ = z[j - 1] + h / 2 * (MyFunc(x[j - 1], y[j - 1], z[j - 1]) + MyFunc(x[j], y[j], z[j]));

        z.pop_back();
        z.push_back(newZ);
        y.pop_back();
        y.push_back(newY);
      }
    }

    return y;
}

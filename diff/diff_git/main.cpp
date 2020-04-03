// leins, 15.04.2018

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "euler_koshi.h"
#include "adams.h"
#include "shooting.h"

using namespace std;

// метод эйлера-коши
// устойчивость метода
/*
int main()
{
  fstream f;
  string fileName = "y_solution.txt";
  double numOfNodes = NUM_OF_NODES;
  double delta = 0.001;

  f.open(fileName, std::ios::trunc | std::ios::out);
  if (!f.is_open())
    cout << "cannot open" << fileName << "file" << endl;
  else
  {
    for (int i = 0; i < 4; i++)
    {
      vector<double> y1 = EulerKoshi(Y0, numOfNodes);
      vector<double> y2 = EulerKoshi(Y0 + delta, numOfNodes);
      double R;

      R = fabs(y1.back() - y2.back());
      cout << "delta = " << delta << endl;
      cout << "y delta = " << R << endl << endl;
      delta *= 10;
    }
  }
}
*/
// метод эйлера-коши
// влияние шага на точность вычислений
/*
int main()
{
  fstream f;
  string fileName = "y_solution.txt";
  double numOfNodes = NUM_OF_NODES;
  double R, eps = E;

  vector<double> y;

  f.open(fileName, std::ios::trunc | std::ios::out);
  if (!f.is_open())
    cout << "cannot open" << fileName << "file" << endl;
  else
  {
    while (eps >= EPS_MAX)
    {
      long int iters = 0;
      vector<double> y1, y2;
      numOfNodes = NUM_OF_NODES;
      do
      {
        y1 = EulerKoshi(Y0, numOfNodes);
        y2 = EulerKoshi(Y0, numOfNodes * 2);
        R = fabs(y1.back() - y2.back()) / 3;
        numOfNodes++;
        iters++;
      }while (R > eps);

      cout << "eps: " << eps << " | iters: " << iters;
      cout << " | nodes: " << numOfNodes ;
      cout << " | last y: " << y1.back() << endl;
      eps /= 10;
      y = y1;
    }
    // y = EulerKoshi(Y0, NUM_OF_NODES);
    vector<double>::iterator it;
    for (it = y.begin(); it != y.end(); it++)
      f << *it << " ";
  }
  return 0;
}
*/
// метод адамса
// влияние шага на точность вычислений
/*
int main()
{
  fstream f;
  string fileName = "y_solution.txt";
  double numOfNodes = NUM_OF_NODES;
  double R, eps = E;

  vector<double> y;

  f.open(fileName, std::ios::trunc | std::ios::out);
  if (!f.is_open())
    cout << "cannot open" << fileName << "file" << endl;
  else
  {
    while (eps >= EPS_MAX)
    {
      long int iters = 0;
      vector<double> y1, y2;
      numOfNodes = NUM_OF_NODES;
      do
      {
        y1 = Adams(Y0, numOfNodes);
        y2 = Adams(Y0, numOfNodes * 2);
        R = fabs(y1.back() - y2.back()) / 3;
        numOfNodes++;
        iters++;
      }while (R > eps);

      cout << "eps: " << eps << " | nodes: " << numOfNodes ;
      cout << " | last y: " << y1.back() << endl;
      eps /= 10;
      y = y1;
    }
    // y = Adams(Y0, numOfNodes);
    vector<double>::iterator it;
    for (it = y.begin(); it != y.end(); it++)
      f << *it << " ";
  }
  return 0;
}
*/
// метод адамса
// устойчивость метода
/*
int main()
{
  fstream f;
  string fileName = "y_solution.txt";
  double numOfNodes = NUM_OF_NODES;
  double delta = 0.001;

  f.open(fileName, std::ios::trunc | std::ios::out);
  if (!f.is_open())
    cout << "cannot open" << fileName << "file" << endl;
  else
  {
    for (int i = 0; i < 4; i++)
    {
      vector<double> y1 = Adams(Y0, numOfNodes);
      vector<double> y2 = Adams(Y0 + delta, numOfNodes);
      double R;

      R = fabs(y1.back() - y2.back());
      cout << "delta = " << delta << endl;
      cout << "y delta = " << R << endl << endl;
      delta *= 10;
    }
  }
}
*/
// метод стрельбы решения краевой задачи
// влияние шага на точность вычислений

int main()
{
  fstream f;
  string fileName = "y_solution.txt";
  double numOfNodes = NUM_OF_NODES;
  double eps = E;

  vector<double> y;

  f.open(fileName, std::ios::trunc | std::ios::out);
  if (!f.is_open())
    cout << "cannot open" << fileName << "file" << endl;
  else
  {
//    while (eps >= EPS_MAX)
  //  {
      vector<double> y1, y2, x;
      double n1 = NUM_OF_NODES, n2 = NUM_OF_NODES * 2;
      vector<double>::iterator it, it2, it3;

      y1 = Shooting(Y0, Y_LAST, n1, eps);
      y2 = Shooting(Y0, Y_LAST, n2, eps);
      x = BuildGrid(n1);

      y2.push_back(1);
      cout << " x  " << " y   " << endl;
      for (it = y1.begin(), it2 = x.begin(), it3 = y2.begin(); it2 != x.end(); it++, it2++, it3++)
      {
        cout << *it2 << " - "  << fabs(*it - *it3) / 3 << endl;
        it3++;
      }

      cout << "eps: " << eps << " | nodes: " << numOfNodes << endl;
      eps /= 10;
      y = y1;
    //}

    //vector<double>::iterator it;
    for (it = y.begin(); it != y.end(); it++)
      f << *it << " ";
  }
  return 0;
}

// метод стрельбы решения краевой задачи
// устойчивость метода
/*
int main()
{
  fstream f;
  string fileName = "y_solution.txt";
  double numOfNodes = NUM_OF_NODES;
  double delta = 0.001;

  f.open(fileName, std::ios::trunc | std::ios::out);
  if (!f.is_open())
    cout << "cannot open" << fileName << "file" << endl;
  else
  {
    for (int i = 0; i < 4; i++)
    {
      vector<double> y1 = Shooting(Y0, Y_LAST, numOfNodes, E);
      vector<double> y2 = Shooting(Y0, Y_LAST + delta, numOfNodes * 2, E);
      double R;

      R = fabs(y1.back() - y2.back());
      cout << "delta = " << delta << endl;
      cout << "y delta = " << R << endl << endl;
      delta *= 10;
    }
  }
}
*/

#ifndef FUNCTION_H
#define FUNCTION_H
// leins, 15.04.2018

#include <vector>

#define A 0
#define B 1.570796325
#define NUM_OF_NODES 9 // 1 for euler koshi
#define Y0 0
#define E 0.01 // 0.01 for euler-coshi
#define EPS_MAX 0.00001 // 0.0000001 for euler-koshi
#define Y_LAST 1 // for shooting method only
double MyFunc(double x, double y, double z);
std::vector<double> BuildGrid(int numOfNodes);

#endif // FUNCTION_H

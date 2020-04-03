#ifndef SHOOTING_H
#define SHOOTING_H
// leins, 08.05.2018

#include "function.h"

std::vector<double> Shooting(double y0, double yLast, double& numOfNodes, double eps);

#endif // SHOOTING_H

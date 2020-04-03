#pragma once
/* leins, 04.03.2018 */
#include "source.h"
/* functions */
double *Spline(double *x, int numOfKnots, int xLen, double *knots, function_t f);
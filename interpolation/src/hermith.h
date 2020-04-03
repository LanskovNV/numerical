#pragma once
/* leins, 19.02.2018 */
#include "source.h"
#define A -12.
#define B 12.
#define STEP 2


#define SIZE 26

/* functions */
double *BuildDiag(function_t f, double *x, const int numOfKnots);
double *Hermit(double *x, double *y, int numOfKnots, int xLen, double *knots);

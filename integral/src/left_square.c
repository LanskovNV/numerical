/* leins, 24.03.2017 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "left_square.h"
#include "source.h"

double LeftSquare(double A, double B)
{
  int i, n = 4; // число узлов
  double I = 0, h = (B - A) / n;
  double *x = malloc(sizeof(double) * (n + 1)); // no check for malloc!!!

  // generate nodes
  for (i = 0; i < n; i++)
	if (i == 0)
	  x[i] = A;
	else if (i == n - 1)
	  x[i] = B;
	else
	  x[i] = x[i - 1] + h;

  // summary
  for (i = 1; i <= n; i++)
    I += func(x[i - 1]);

  free(x);
  return I * h;
} // end of function

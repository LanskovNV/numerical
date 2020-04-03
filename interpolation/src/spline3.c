/* leins, 045.03.2018 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "spline3.h"
#include "source.h"

static double GetDelta(double x1, double x2, function_t f)
{
  return (f.func(x2) - f.func(x1)) / (x2 - x1);
} /* end of function */
static double *GetA(int numOfKnots, double *knots, function_t f)
{
  int k;
  double *a = malloc(sizeof(double) * (numOfKnots - 1));

  if (a == NULL)
	printf("no memory for a koef\n");
  else
	for (k = 0; k < numOfKnots - 1; k++)
	  a[k] = f.func(knots[k + 1]);

  return a;
} /* end of function */

static double *GetC(int numOfKnots, double *knots, function_t f)
{
  double *delta = malloc(sizeof(double) * (numOfKnots - 1));
  double *lambda = malloc(sizeof(double) * (numOfKnots - 1));
  double *c = malloc(sizeof(double) * (numOfKnots));

  if (delta == NULL || lambda == NULL || c == NULL)
	printf("no memory for c koef\n");
  else
  {
	int k;
	double h1 = knots[1] - knots[0];
	double h2 = knots[2] - knots[1];
	
	c[numOfKnots - 1] = 0;
	c[0] = 0;
	delta[0] =  -h2 / (2 * (h1 + h2));
	lambda[0] = (3 * GetDelta(knots[1], knots[2], f) - 3 * GetDelta(knots[0], knots[1], f))
	  / (2 * (h1 + h2));

	for (k = 2; k <= numOfKnots - 1; k++)
	{
    double hk = knots[k] - knots[k - 1];
    double hkOld = knots[k - 1] - knots[k - 2];

	  delta[k - 1] = -hk / (2 * hkOld + 2 * hk + hkOld * delta[k - 2]);

	  lambda[k - 1] = ( 3 * GetDelta(knots[k - 1], knots[k], f)
		- 3 * GetDelta(knots[k - 2], knots[k - 1], f)
		- hkOld * lambda[k - 2] )
		/ (2 * hkOld + 2 * hk + hkOld * delta[k - 2]);
	}
	
	for (k = numOfKnots - 1; k > 1; k--)
	{
	  c[k - 1] = delta[k - 1] * c[k] + lambda[k - 1];
	}
  }

  free(delta);
  free(lambda);
  return c;
} /* end of function */
static double *GetD(int numOfKnots, double *knots, double *c)
{
  int k;
  double *d = malloc(sizeof(double) * (numOfKnots - 1));

  if (d == NULL)
	printf("no memory for a koef\n");
  else
	for (k = 0; k < numOfKnots - 1; k++)
		d[k] = (c[k + 1] - c[k]) / (3 * (knots[k + 1] - knots[k]));
  return d;
} /* end of function */
static double *GetB(int numOfKnots, double *knots, double *c, function_t f)
{
  int k;
  double *b = malloc(sizeof(double) * (numOfKnots - 1));

  if (b == NULL)
	printf("no memory for a koef\n");
  else
	for (k = 0; k < numOfKnots - 1; k++)
	{
	  double hk = knots[k + 1] - knots[k];
	  b[k] = GetDelta(knots[k], knots[k + 1], f) + (2 * hk * c[k + 1] + hk * c[k]) / 3;
	}
  return b;
} /* end of function */

double *Spline(double *x, int numOfKnots, int xLen, double *knots, function_t f)
{
  int i, k;
  double *a, *b, *c, *d, *result;

  result = malloc(sizeof(double) * xLen);
  a = GetA(numOfKnots, knots, f);
  c = GetC(numOfKnots, knots, f);
  d = GetD(numOfKnots, knots, c);
  b = GetB(numOfKnots, knots, c, f);
  if (a == NULL || b == NULL || c == NULL || d == NULL || result == NULL)
	printf("not enougth memory for koef\n");
  else
  {
	for (i = 0, k = 1; i < xLen; i++)
	{
	  if (x[i] > knots[k])
        k += 1;

      result[i] = a[k - 1] + b[k - 1] * (x[i] - knots[k])
          + c[k] * pow(x[i] - knots[k], 2)
          + d[k - 1] * pow(x[i] - knots[k], 3);
	}
  }
  free(a);
  free(b);
  free(c);
  free(d);
  return result;
} /* end of function */

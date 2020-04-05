/* leins, 24.03.2018 */
#include <stdio.h>
#include <math.h>
#include "source.h"
#include "left_square.h"
#include "square_gauss.h"

double Runge(double A, double B, double eps, func_t *func)
{
  double I, I2, R = 0;
  double H = B - A, h = (B - A) / 2;
  int n = 1, i; 

  do
  {
	double a1 = A, b1 = A + H;
	double a2 = A, b2 = A + h;

	I = 0, I2 = 0;

	for (i = 0; i < n; i++)
	{
	  I += func(a1, b1);
	  a1 += H;
	  b1 += H;
	}
	for (i = 0; i < 2 * n; i++)
	{
	  I2 += func(a2, b2);
	  a2 += h;
	  b2 += h;
	}

	if (func == SquareGauss)
	  R = (I2 - I) / 512;
	else
	  R = (I2 - I);
	n *= 2;
	H = (B - A) / n;
	h = (B - A) / (2 * n);
  } while (fabs(R) > eps);

  printf("num of intervals - %i\n", n / 2);
  return I;
} // end of function

double func(double x)
{
  return (2 - x * x) * cos(x) + 2 * x * sin(x);
  // return pow(x, 7);
} // end of function

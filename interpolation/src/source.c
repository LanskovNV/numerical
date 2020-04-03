/* leins, 19.02.2018 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "source.h"
#include "hermith.h"

double GetW(double a, double b, double step, double xj, int n)
{
  double i;
  double res = 1;
  double fact = 1;

  //for (i = a; i <= b; i += step)
  for (i = a; i <= b; i += (abs(a) + abs(b)) / step)
  {
	if (i != xj)
	  res *= (xj - i);
	fact *= n;
	n--;
  }
  return fabs(res) / fact;
}
double my_fabs(double x)
{
  if (x < 0)
    x *= -1.0;
  return x;
}
double FindMaxDelta(double a, double b, double step, double *y, int xLen, function_t f)
{
  double max = 0, maxDelta = fabs(f.func(a) - y[0]);
  double i;
  int k;

  for (i = a, k = 0; i <= b && k < xLen; i += step, k++)
  {
  if (my_fabs(f.func(i) - y[k]) > maxDelta)
	{
	  max = k;
    maxDelta = my_fabs(f.func(i) - y[k]);
	}
  }

  printf("max delta: %lf\n", maxDelta);
  return max;
}
void FuncInit(function_t *func, char *name, double(*f)(double), double(*der)(double))
{
  func->name = malloc(strlen(name) + 1);
  strcpy(func->name, name);
  func->func = f;
  func->der = der;
} /* end of function */
void FuncFree(function_t *func)
{
  free(func->name);
} /* end of function */
double Func1(double x)
{
  return (2 - pow(x, 2)) * cos(x) + 2 * x * sin(x);
} /* end of function */
double Func1Der(double x)
{
  return pow(x, 2) * sin(x);
} /* end of function */
double Runge(double x)
{
  return 1 / (1 + 25 * pow(x, 2));
} /* end of function */
double RungeDer(double x)
{
  return -50 * x / pow(1 + 25 * pow(x, 2), 2);
} /* end of function */
double Test(double x)
{
  return pow(x, 8) + 1;
}
double TestDer(double x)
{
  return 8 * pow(x, 7);
}

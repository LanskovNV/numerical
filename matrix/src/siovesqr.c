/* leins, 29.11.2017 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

#define EPS1 0.0001
static int Signum(double x)
{
  if (x > 0)
    return 1;
  else
    return -1;
}
double myFabs(double x)
{
  if (x < 0)
    return x * -1.;
  else
    return x;
}
double MySqrt(double a)
{
  double x = a / 2.;

  while (fabs((a / x) - x) > EPS1)
    x = (x + (a / x)) / 2;
  return x;
}
void SolveSqr(matrix_t matrix, double *b, double *x)
{
  matrix_t D, U, G, ym;
  double d[MATR_SIZE];
  int i, j, k;

  MatrInit(&D, MATR_SIZE, MATR_SIZE);
  MatrInit(&G, MATR_SIZE, MATR_SIZE);
  MatrInit(&ym, MATR_SIZE, 1);
  MatrInit(&U, MATR_SIZE, MATR_SIZE);
  //build u matrix
  for (i = 0; i < matrix.numOfStrings; i++)
  {
    double sum1 = 0;

    for (k = 0 ; k < i; k++) //
      sum1 += U.matr[k][i] * U.matr[k][i] * d[k];
    d[i] = Signum(matrix.matr[i][i] - sum1);
    U.matr[i][i] = sqrt(myFabs(matrix.matr[i][i] - sum1));

    for (j = 0; j < matrix.numOfVectors; j++)
    {
      if (j < i)
        U.matr[i][j] = 0;
      if (j > i)
      {
        double sum2 = 0;

        for (k = 0; k < i; k++) //
          sum2 += U.matr[k][i] * U.matr[k][j] * d[k];
        U.matr[i][j] = (matrix.matr[i][j] - sum2) / (U.matr[i][i] * d[i]);
      }
    }
  }
  // Build D matrix
  for (i = 0 ;i < matrix.numOfStrings; i++)
    for (j = 0; j < matrix.numOfVectors; j++)
    {
      if (i == j)
        D.matr[i][j] = d[i];
      else
        D.matr[i][j] = 0;
    }
  // find x
  G = Multiplex(Trans(U), D);
  ym = Multiplex(AntiMatr(G), VectToMatr(b, MATR_SIZE));
  MatrToVect(Multiplex(AntiMatr(U), ym), x);
} /* end of function */

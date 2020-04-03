/* leins, 06.12.2017*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "leverie.h"

double Func(poly_t p, double x)
{
  return pow(x, 10) + p.p[0] * pow(x, 9)
      + p.p[1] * pow(x, 8) + p.p[2] * pow(x, 7)
      + p.p[3] * pow(x, 6) + p.p[4] * pow(x, 5)
      + p.p[5] * pow(x, 4) + p.p[6] * pow(x, 3)
      + p.p[7] * pow(x, 2) + p.p[8] * x
      + p.p[9];
}
void FindRoots(matrix_t matrix, poly_t p, double eps, inter_t *iter)
{
  double norm = GetSecondNorm(matrix);
  double s = 0, sOld = 0;
  int i = 0;
  double fVal = 0, fOld = Func(p, s);

  while (s <= norm * 2)
  {
    fVal = Func(p, s);
    if (fVal * fOld <= 0)
    {
      iter[i].a = sOld;
      iter[i].b = s;
      i++;
    }
    if (i > 9)
      return;
    sOld = s;
    s += eps;
    fOld = fVal;
  }
} /* end of fucntion */
static matrix_t MatrPow(matrix_t matrix, int pow)
{
  matrix_t result = matrix;
  int i;

  for (i = 0; i < pow; i++)
    result = Multiplex(result, matrix);
  return result;
} /* end of function */

double DiagSum(matrix_t matrix)
{
  int i;
  double res = 0;

  for (i = 0; i < matrix.numOfStrings; i++)
    res += matrix.matr[i][i];
  return res;
} /* end of fucntion */

void PolyInit(poly_t *p, int pow)
{
  p->p = malloc(sizeof(double) * pow);
  p->pow = pow;
} /* end of function */

void PolyFree(poly_t *p)
{
  free(p->p);
} /* end of function */

poly_t Leverie(matrix_t matrix)
{
  poly_t poly;
  double s[matrix.numOfStrings];
  int i;

  PolyInit(&poly, matrix.numOfStrings);
  for (i = 0; i < matrix.numOfStrings; i++)
    s[i] = DiagSum(MatrPow(matrix, i));
  for (i = 0; i < matrix.numOfStrings; i++)
  {
    double sum = 0;
    int k;

    for (k = 0; k < i; k++)
      sum += poly.p[k] * s[i - k - 1];
    poly.p[i] = (s[i] - sum) / (double)(i + 1);
  }
  if (matrix.numOfStrings % 2 == 0)
    for (i = 0; i < matrix.numOfStrings; i++)
      poly.p[i] *= -1.0;
  return poly;
} /* end of function */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "solve.h"
#include "matrix.h"

int SolveIter(matrix_t matrix, double *b, double *x, double eps)
{
  matrix_t xOld, xNew, c;
  matrix_t B, delta, D;
  int i;
  double E = eps, tmp1 = 0, tmp2 = 0;
  int numOfIters = 0;

  MatrInit(&xOld, MATR_SIZE, 1);
  MatrInit(&xNew, MATR_SIZE, 1);
  MatrInit(&c, MATR_SIZE, 1);
  MatrInit(&B, MATR_SIZE, MATR_SIZE);
  MatrInit(&delta, MATR_SIZE, MATR_SIZE);
  MatrInit(&D, MATR_SIZE, MATR_SIZE);

  // get first
  do
  {
    delta = Delta(E);
    B = Multiplex(delta, matrix);
    E *= 0.1;
    numOfIters++;
  } while (GetMatrNorm(B) >= 1);
  D = Summary(AntiMatr(matrix), delta, -1);
  for (i = 0; i < MATR_SIZE; i++)
    xOld.matr[i][0] = b[i];
  c = Multiplex(D, xOld);
  xOld = c;

  // find x
  xNew = xOld;
  do
  {
    xOld = xNew;
    xNew = Summary(Multiplex(B, xOld), c, 1);
    tmp1 = GetMatrNorm(Summary(xNew, xOld, -1));
    tmp2 = GetMatrNorm(B);
    numOfIters++;
  } while(tmp1 > (1 - tmp2) * eps / tmp2);

  for (i = 0; i < MATR_SIZE; i++)
  {
    x[i] = xNew.matr[i][0];
  }
  return numOfIters;
} /* end of function */

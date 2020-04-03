/* leins, 13.12.2017 */
#include <stdio.h>
#include <math.h>
#include "matrix.h"
#include "qr.h"
#include "jacobi.h"

int Compare(matrix_t x1, matrix_t x2, double eps)
{
  int i;

  for (i = 0; i < MATR_SIZE; i++)
    if (fabs(fabs(x1.matr[i][0]) - fabs(x2.matr[i][0])) > eps)
      return 0;
  return 1;
}
matrix_t GetSVect(matrix_t matrix, double L, double eps)
{
  matrix_t x, xOld, y;

  double yTmp[MATR_SIZE];
  int i;

  MatrInit(&x, MATR_SIZE, 1);
  MatrInit(&xOld, MATR_SIZE, 1);
  MatrInit(&y, MATR_SIZE, 1);
  for (i = 0; i < MATR_SIZE; i++)
    x.matr[i][0] = 1;

  do
  {
    xOld = x;
    Solve(Summary(matrix, Alpha(Eye(), L), -1), Trans(x).matr[0], yTmp);
    for (i = 0; i < MATR_SIZE; i++)
      y.matr[i][0] = yTmp[i];
    x = Alpha(y, 1 / GetSecondNorm(y));
  } while (!Compare(x, xOld, eps));

  return x;
} /* end of function */

static double sign(double x)
{
  if (x >= 0)
    return 1.0;
  else
    return -1.0;
} /* end of function */

matrix_t Hessenberg(matrix_t matrix)
{
  matrix_t W, E, H, B;
  int i, j;

  MatrInit(&W, MATR_SIZE, 1);
  B = matrix;
  E = Eye();
  for (i = 0; i < MATR_SIZE - 2; i++)
  {
    double s, m, sum = 0;

    for (j = i + 1; j < MATR_SIZE; j++)
      sum += B.matr[j][i] * B.matr[j][i];
    s = sign(-1.0 * B.matr[i + 1][i]) * sqrt(sum);
    m = 1 / sqrt(2 * s * (s - B.matr[i + 1][i]));
    for (j = 0; j < MATR_SIZE; j++)
      if (j > i + 1)
        W.matr[j][0] = m * B.matr[j][i];
      else if (j < i + 1)
        W.matr[j][0] = 0;
      else
        W.matr[j][0] = m * (B.matr[j][i] - s);
    H = Summary(E, Alpha(Multiplex(W, Trans(W)),2.), -1.);
    B = Multiplex(Multiplex(H, B), H);
  }
  return B;
} /* end of fucntion */

static matrix_t Givens(matrix_t matrix)
{
  matrix_t B = matrix, G, Gall = Eye();
  int j;


  for (j = 0; j < MATR_SIZE - 1; j++)
  {
    double c, s, t;

    G = Eye();
    if (B.matr[j+1][j] == 0)
      c = 0, s = 1;
    else
    {
      t = B.matr[j][j] / B.matr[j+1][j];
      c = 1 / sqrt(1 + t*t);
      s = t*c;
    }
    G.matr[j][j + 1] = c;
    G.matr[j][j] = s;
    G.matr[j + 1][j + 1] = s;
    G.matr[j+1][j] = -1. * c;
    //PutMatrix(G);
    B = Multiplex(G, B);
    Gall = Multiplex(G, Gall);
    //PutMatrix(Gall);
  }
  B = Multiplex(B, Trans(Gall));

  return B;
}/* end of function */
static double GetExit(matrix_t matrix)
{
  double sum = 0;
  int i;

  for (i = 0; i < MATR_SIZE - 1; i++)
    sum += fabs(matrix.matr[i+1][i]);
  return sum / (double)(MATR_SIZE - 1);
}
matrix_t Qr(matrix_t matrix, double eps)
{
  matrix_t B = matrix;

  B = Hessenberg(B);
  while (GetExit(B) > eps)
  {
    B = Givens(B);
  }
 // PutMatrix(B);
  return B;
} /* end of function */

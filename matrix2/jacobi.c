/* leins, 06.12.2017 */
#include <stdio.h>
#include <math.h>
#include "matrix.h"
#include "jacobi.h"
static double sign(double x)
{
  if (x >= 0)
    return 1.0;
  else
    return -1.0;
} /* end of function */
point_t ChooseElem(matrix_t matrix)
{
  int i, j;
  double maxElem = fabs(matrix.matr[0][1]); // !!!
  point_t tmp;

  tmp.i = 0;
  tmp.j = 1;
  for (i = 0; i < matrix.numOfStrings; i++)
    for (j = 0; j < matrix.numOfVectors; j++)
      if (i != j)
        if (fabs(matrix.matr[i][j]) > maxElem)
        {
          maxElem = fabs(matrix.matr[i][j]);
          tmp.i = i;
          tmp.j = j;
        }
  return tmp;
} /* end of function */
static double GetFrNorm(matrix_t matrix)
{
  double sum = 0;
  int i, j;

  for (i = 0; i < matrix.numOfStrings; i++)
    for (j = 0; j < matrix.numOfVectors; j++)
      sum += matrix.matr[i][j] * matrix.matr[i][j];
  return sqrt(sum);
} /* end of function */
static matrix_t GetVB(matrix_t B)
{
  int i, j;

  for (i = 0; i < B.numOfStrings; i++)
    for (j = 0; j < B.numOfVectors; j++)
      if (i == j)
        B.matr[i][j] = 0;
  return B;
} /* end of matrix */
matrix_t GetRotMatr(matrix_t T, point_t p, double c, double s)
{
  int i, j;
  MatrInit(&T, MATR_SIZE, MATR_SIZE);
  // T = E
  for (i = 0; i < MATR_SIZE; i++)
    for (j = 0; j < MATR_SIZE; j++)
    {
     if (i == j)
     {
       if (i == p.i || i == p.j)
         T.matr[i][j] = c;
       else
         T.matr[i][j] = 1;
     }
     else
     {
       if (i == p.i && j == p.j)
         T.matr[i][j] = -1.0 * s;
       else if (i == p.j && j == p.i)
         T.matr[i][j] = s;
       else
         T.matr[i][j] = 0;
     }
    }
  return T;
} /* end of function */
matrix_t Jacobi(matrix_t matrix, double eps, matrix_t *T1)
{
  matrix_t B, T;
  point_t p;
  double  d, c, s, signum;
  int cnt;

  B = matrix;
  while (GetFrNorm(GetVB(B)) >= eps)
  {
    double tmp = B.matr[p.i][p.i] - B.matr[p.j][p.j];

    p = ChooseElem(B);
    d = sqrt(pow(tmp, 2) + 4 * pow(B.matr[p.i][p.j], 2));
    signum = sign(B.matr[p.i][p.j] * tmp);
    c = sqrt((1 + fabs(tmp) / d) / 2);
    s = signum * sqrt((1 - fabs(tmp) / d) / 2);
    T = GetRotMatr(T, p, c, s);
    B = Multiplex(Multiplex(Trans(T), B), T);
    *T1 = Multiplex(*T1, T);
    cnt++;
  }
  printf("%i\n", cnt);
  return B;
} /* end of function */

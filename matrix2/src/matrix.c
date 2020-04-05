/* leins, 18.11.2017 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

/* source */
void MatrInit(matrix_t *matr, int str, int vect)
{
  matr->numOfStrings = str;
  matr->numOfVectors = vect;
} /* end of function */

void CreateMatrix(matrix_t *good, matrix_t *bad)
{
  int i, j;
  double matrix_good[MATR_SIZE][MATR_SIZE] = {  {3.2233326e+000, -4.2417286e-004,  2.5305773e-002,  1.3958073e+000,  3.5080231e-001,  1.9404164e+000,  1.2573343e+000,  6.2137981e-002,  3.5520984e-001,  3.8658596e-003},
                                                {-4.2417286e-004,  9.7009962e+000, -1.1533379e-001, -5.2360661e-002, -7.4186732e-002,  1.5245963e-003, -3.3668290e-002, -5.0527162e-002, -7.0750011e-002, -2.3318899e-002},
                                                {2.5305773e-002, -1.1533379e-001,  6.8751658e+000, -1.1945888e+000, -1.7273318e+000,  7.7147442e-002, -7.6043477e-001, -1.1802331e+000, -1.6468709e+000, -5.4522252e-001},
                                                {1.3958073e+000, -5.2360661e-002, -1.1945888e+000,  5.4882262e+000, -4.8402314e-001,  1.6656161e+000,  7.1385019e-001, -4.7994461e-001, -4.4403888e-001, -2.4259249e-001},
                                                {3.5080231e-001, -7.4186732e-002, -1.7273318e+000, -4.8402314e-001,  6.9642619e+000,  4.4366132e-001, -2.3320796e-001, -7.4566557e-001, -9.8595240e-001, -3.4951380e-001},
                                                {1.9404164e+000,  1.5245963e-003,  7.7147442e-002,  1.6656161e+000,  4.4366132e-001,  3.7038580e+000,  1.4948360e+000,  9.3931748e-002,  4.4744232e-001,  1.4125041e-002},
                                                {1.2573343e+000, -3.3668290e-002, -7.6043477e-001,  7.1385019e-001, -2.3320796e-001,  1.4948360e+000,  4.9519063e+000, -2.9408530e-001, -2.0659959e-001, -1.5470619e-001},
                                                {6.2137981e-002, -5.0527162e-002, -1.1802331e+000, -4.7994461e-001, -7.4566557e-001,  9.3931748e-002, -2.9408530e-001,  8.6423615e+000, -7.1028860e-001, -2.3867730e-001},
                                                {3.5520984e-001, -7.0750011e-002, -1.6468709e+000, -4.4403888e-001, -9.8595240e-001,  4.4744232e-001, -2.0659959e-001, -7.1028860e-001,  6.9863265e+000, -3.3324884e-001},
                                                {3.8658596e-003, -2.3318899e-002, -5.4522252e-001, -2.4259249e-001, -3.4951380e-001,  1.4125041e-002, -1.5470619e-001, -2.3867730e-001, -3.3324884e-001,  9.4846833e+000}
  };
  double matrix_bad[MATR_SIZE][MATR_SIZE] = {  {1.5832907e+008,  7.1384358e+006,  6.2099163e+007,  1.0353597e+007,  2.1778177e+007,  1.8433833e+008,  1.5316536e+008,  6.4729904e+007, -1.0635788e+008, -2.2518196e+007},
                                            {7.1384358e+006,  3.2184762e+005,  2.7998075e+006,  4.6680306e+005,  9.8189251e+005,  8.3110919e+006,  6.9056246e+006,  2.9184173e+006, -4.7952593e+006, -1.0152570e+006},
                                            {6.2099163e+007,  2.7998075e+006,  2.4357124e+007,  4.0608447e+006,  8.5417457e+006,  7.2300412e+007,  6.0073875e+007,  2.5388088e+007, -4.1715486e+007, -8.8320157e+006},
                                            {1.0353597e+007,  4.6680306e+005,  4.0608447e+006,  6.8639174e+005,  1.4241383e+006,  1.2054419e+007,  1.0015924e+007,  4.2328676e+006, -6.9554968e+006, -1.4725725e+006},
                                            {2.1778177e+007,  9.8189251e+005,  8.5417457e+006,  1.4241383e+006,  3.0634637e+006,  2.5355748e+007,  2.1067852e+007,  8.9034680e+006, -1.4636358e+007, -3.0980257e+006},
                                            {1.8433833e+008,  8.3110919e+006,  7.2300412e+007,  1.2054419e+007,  2.5355748e+007,  2.1537734e+008,  1.7832102e+008,  7.5350421e+007, -1.2447532e+008, -2.6278466e+007},
                                            {1.5316536e+008,  6.9056246e+006,  6.0073875e+007,  1.0015924e+007,  2.1067852e+007,  1.7832102e+008,  1.5555709e+008,  6.2512125e+007, -1.0823216e+008, -2.2289632e+007},
                                            {6.4729904e+007,  2.9184173e+006,  2.5388088e+007,  4.2328676e+006,  8.9034680e+006,  7.5350421e+007,  6.2512125e+007,  6.5429329e+007, -5.6352355e+007, -1.0424581e+007},
                                            {-1.0635788e+008, -4.7952593e+006, -4.1715486e+007, -6.9554968e+006, -1.4636358e+007, -1.2447532e+008, -1.0823216e+008, -5.6352355e+007,  8.2420140e+007, -4.5890543e+007},
                                            {-2.2518196e+007, -1.0152570e+006, -8.8320157e+006, -1.4725725e+006, -3.0980257e+006, -2.6278466e+007, -2.2289632e+007, -1.0424581e+007, -4.5890543e+007,  1.7092928e+009}


  };
  MatrInit(good, MATR_SIZE, MATR_SIZE);
  MatrInit(bad, MATR_SIZE, MATR_SIZE);
  for (i = 0 ; i < MATR_SIZE; i++)
    for (j = 0 ; j < MATR_SIZE; j++)
    {
      good->matr[i][j] = matrix_good[i][j];
      bad->matr[i][j] = matrix_bad[i][j];
    }
} /* end of function */

double GetSecondNorm(matrix_t matrix)
{
  int i, j;
  double max = 0;

  for (i = 0; i < matrix.numOfVectors; i++)
  {
    double sum = 0;

    for (j = 0; j < matrix.numOfStrings; j++)
      sum += pow(matrix.matr[i][j],2);
    sum = sqrt(sum);
    if (sum > max)
      max = sum;
  }
  return max;
} /* end of function */

void GetMatrix(matrix_t *matrix, char *fileName)
{
  int i, j;
  double tmp = 0;
  FILE *stream;

  if ((stream = fopen(fileName, "r")) == NULL)
  {
    printf("canot get matrix from %s\n", fileName);
    return;
  }

  for (i = 0 ; i < matrix->numOfStrings; i++)
    for (j = 0; j < matrix->numOfVectors; j++)
    {
       fscanf(stream, "%lf", &tmp);
       matrix->matr[i][j] = tmp;
    }
  fclose(stream);
} /* end of function */

void PutMatrix(matrix_t matrix)
{
  int i, j;

  for (i = 0 ; i < matrix.numOfStrings; i++)
  {
    for (j = 0; j < matrix.numOfVectors; j++)
      printf("%lf ", matrix.matr[i][j]);
    printf("\n");
  }
} /* end of function */

/* translate */
matrix_t VectToMatr(double *vect, int size)
{
  int i;
  matrix_t matr;

  MatrInit(&matr, size, 1);
  for (i = 0 ; i < size; i++)
    matr.matr[i][0] = vect[i];
  return matr;
} /* end of function */

void MatrToVect(matrix_t matr, double *vect)
{
  int i;

  for (i = 0 ; i < matr.numOfStrings; i++)
    vect[i] = matr.matr[i][0];
} /* end of function */

/* functions */
matrix_t Eye()
{
  matrix_t E;
  int i, j;

  MatrInit(&E, MATR_SIZE, MATR_SIZE);
  for (i = 0; i < MATR_SIZE; i++)
    for (j = 0; j < MATR_SIZE; j++)
      if (i == j)
        E.matr[i][j] = 1;
      else
        E.matr[i][j] = 0;
  return E;
} /* end of function */
double GetMatrNorm(matrix_t matrix)
{
  int i, j;
  double max = 0;

  for (i = 0; i < matrix.numOfVectors; i++)
  {
    double sum = 0;
    for (j = 0; j < matrix.numOfStrings; j++)
    {
      sum += fabs(matrix.matr[j][i]);
    }
    if (sum > max)
      max = sum;
  }
  return max;
} /* end of function */

matrix_t Delta(double eps)
{
  matrix_t matrix;
  uint timer = (uint)time(0);
  int i, j;

  MatrInit(&matrix, MATR_SIZE, MATR_SIZE);
  for (i = 0 ; i < MATR_SIZE; i++)
    for (j = 0 ; j < MATR_SIZE; j++)
    {
      double x;

      srand(timer++);
      x = rand() % 10;
      if (x == 0)
        x++;
      matrix.matr[i][j] = x * eps;
    }

  return matrix;
} /* end of function */

matrix_t Summary(matrix_t A, matrix_t B, double sign)
{
  int i, j;
  matrix_t matrix;

  MatrInit(&matrix, A.numOfStrings, A.numOfVectors);
  if (A.numOfStrings != B.numOfStrings ||
      A.numOfVectors != B.numOfVectors)
  {
    printf("error in summary");
    return matrix;
  }
  for (i = 0 ; i < A.numOfStrings; i++)
    for (j = 0; j < A.numOfVectors; j++)
    {
      matrix.matr[i][j] = A.matr[i][j] + sign * B.matr[i][j];
    }
  return matrix;
} /* end of function */

matrix_t Trans(matrix_t A)
{
  int i, j;
  matrix_t matrix;

  MatrInit(&matrix, A.numOfVectors, A.numOfStrings);
  for (i = 0; i < A.numOfStrings; i++)
    for (j = 0; j < A.numOfVectors; j++)
    {
      matrix.matr[j][i] = A.matr[i][j];
    }
  return matrix;
} /* end of function */

matrix_t Multiplex(matrix_t A, matrix_t B)
{
  int i, j, k;
  matrix_t matrix;

  MatrInit(&matrix, A.numOfStrings, B.numOfVectors);
  for (k = 0; k < A.numOfStrings; k++)
  {
    for (i = 0; i < B.numOfVectors; i++)
    {
      double sum = 0;
      for (j = 0; j < B.numOfStrings; j++)
        sum += A.matr[k][j] * B.matr[j][i];
      matrix.matr[k][i] = sum;
    }
  }
  return matrix;
} /* end of function */

matrix_t Alpha(matrix_t matrix, double alpha)
{
  int i, j;

  for (i = 0 ; i < matrix.numOfStrings; i++)
    for (j = 0 ; j < matrix.numOfStrings; j++)
      matrix.matr[i][j] *= alpha;
  return matrix;
} /* end of function */

/* Solve and Inv */
void Solve(matrix_t matrix, double *b, double *x)
{
  int i, j, k;
  double c, s, tmp, a, b1;

  // прямой ход
  for (i = 0; i < matrix.numOfStrings - 1; i++)
  {
    for (j = i + 1; j < matrix.numOfStrings; j++)
    {
      a = matrix.matr[i][i];
      b1 = matrix.matr[j][i];
      c = a / sqrt(a * a + b1 * b1);
      s = b1 / sqrt(a * a + b1 * b1);
      for (k = 0; k < matrix.numOfStrings; k++)
      {
        tmp = matrix.matr[i][k];
        matrix.matr[i][k] = c * matrix.matr[i][k] + s * matrix.matr[j][k];
        matrix.matr[j][k] = -s * tmp + c * matrix.matr[j][k];
      }
      tmp = b[i];
      b[i] = c * b[i] + s * b[j];
      b[j] = -s * tmp + c * b[j];
    }
  }

  // обратный ход
  for (k = matrix.numOfStrings - 1; k >= 0; k--)
  {
    double sum = 0;

    for (j = k + 1; j < matrix.numOfStrings; j++)
    {
      sum += matrix.matr[k][j] * x[j];
    }
    x[k] = (b[k] - sum) / matrix.matr[k][k];
  }
} /* end of function */

matrix_t AntiMatr(matrix_t matrix)
{
  matrix_t E, xm;
  int i, j;

  MatrInit(&E, MATR_SIZE, MATR_SIZE);
  MatrInit(&xm, MATR_SIZE, MATR_SIZE);

  for (i = 0; i < MATR_SIZE; i++)
    for (j = 0; j < MATR_SIZE; j++)
      if (i == j)
        E.matr[i][j] = 1;
      else
        E.matr[i][j] = 0;
  for (i = 0; i < MATR_SIZE; i++)
    Solve(matrix, E.matr[i], xm.matr[i]);
  return Trans(xm);

} /* end of function */


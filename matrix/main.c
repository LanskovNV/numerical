/* leins, 18.11.2017 */
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

#include "solve_iter.h"
#include "solvesqr.h"

#define EPS 0.001
int main()
{
  int i;
  matrix_t good, bad, bm, xm;//, delta, xMatr, xB;
  matrix_t small, small2, small3, work;
  double x[MATR_SIZE];
  int numOfIters = 0;
  //double xb[MATR_SIZE];
  //double xmatr[MATR_SIZE];
  //double bDelta[MATR_SIZE];
  double b[MATR_SIZE] = { -12, 22, 51, 67, 2, 3, 0, 8, 10, 4};
  //double k1, k2, tmp1, tmp2;

  CreateMatrix(&good, &bad);
  MatrInit(&small, MATR_SIZE, MATR_SIZE);
  MatrInit(&small2, MATR_SIZE, MATR_SIZE);
  MatrInit(&small3, MATR_SIZE, MATR_SIZE);
  GetMatrix(&small, "small.txt");
  GetMatrix(&small2, "small2.txt");
  GetMatrix(&small3, "small3.txt");


  work = small; // change matrix
  work = Multiplex(Multiplex(small, small2), small3);
  numOfIters = SolveIter(work, b, x, EPS);
  for (i = 0; i < MATR_SIZE; i++)
    printf("%lf ", x[i]);
  printf("\n");
  xm = VectToMatr(x, MATR_SIZE);
  bm = VectToMatr(b, MATR_SIZE);

  bm = Multiplex(work, xm);
  for (i = 0; i < MATR_SIZE; i++)
    printf("%lf ", bm.matr[i][0]);
  printf("\n\n");
  printf("EPS - %lf\n", EPS);

  printf("cond: ");
  printf("%lf", GetMatrNorm(work) * GetMatrNorm(AntiMatr(work)));
  printf("\n");

  /*
  delta = Delta(EPS);
  // matr delta
  SolveSqr(Summary(good, delta, 1), b, xmatr);          // change matrix
  for (i = 0; i < MATR_SIZE; i++)
    printf("%lf ", xmatr[i]);
  printf("\n");
  xMatr = VectToMatr(xmatr, MATR_SIZE);
  tmp1 = GetMatrNorm(xMatr) / GetMatrNorm(xm);
  tmp2 = GetMatrNorm(good) / GetMatrNorm(Summary(good, delta, 1)); // change matrix
  k1 = tmp1 / tmp2;

  // b delta
  delta = DeltaVect(EPS);
  xMatr = VectToMatr(b, MATR_SIZE);
  xMatr = Summary(xMatr, delta, 1);
  MatrToVect(xMatr, bDelta);
  SolveSqr(good, bDelta, xb);          // change matrix
  for (i = 0; i < MATR_SIZE; i++)
    printf("%lf ", xb[i]);
  printf("\n");
  xB = VectToMatr(xb, MATR_SIZE);
  tmp1 = GetMatrNorm(xB) / GetMatrNorm(xm);
  tmp2 = GetMatrNorm(xMatr) / GetMatrNorm(bm);
  k2 = tmp1 / tmp2;

  printf("k1 ");
  printf("%lf", k1);
  printf("\n");

  printf("k2 ");
  printf("%lf", k2);
  printf("\n");
  */
  bm = VectToMatr(b, MATR_SIZE);
  printf("||AX - b|| = ");
  printf("%lf", GetMatrNorm(Summary(Multiplex(work, xm), bm, -1)));
  printf("\n");
  printf("num of iters :\n");
  printf("%i", numOfIters);
  printf("\n");

  return 0;
}

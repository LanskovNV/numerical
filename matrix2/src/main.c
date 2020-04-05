/* leins, 06.12.2017 */
#include <stdio.h>
#include "matrix.h"
#include "leverie.h"
#include "jacobi.h"
#include "qr.h"
#include "solve_iter.h"

#define EPS 3
/*
 * main for qr
*/
/*
int main(void)
{
  int i, j;
  matrix_t matrix, ans, H;
  matrix_t x;

  MatrInit(&x, MATR_SIZE, 1);
  MatrInit(&matrix, MATR_SIZE, MATR_SIZE);
  MatrInit(&H, MATR_SIZE, MATR_SIZE);
  GetMatrix(&matrix, "badASYM.txt");
  ans = Qr(matrix, EPS);

  for (i = 0; i < MATR_SIZE; i++)
  {
    printf("%lf\n", ans.matr[i][i]);

    x = GetSVect(matrix, ans.matr[i][i], EPS);
    for (j = 0; j < MATR_SIZE; j++)
      printf("%lf ", x.matr[j][0]);
    printf("\n");
    printf("||Lx - Ax||:\n");
    printf("%lf\n\n", GetMatrNorm(Multiplex(Summary(matrix, Alpha(Eye(), ans.matr[i][i]), -1), x)));

}
  return 0;
}
*/

/*
 * main for jacobi
*/

int main(void)
{
  matrix_t matrix = Eye(), T = Eye(), ans = Eye();
  int i, j;
  matrix_t x;

  MatrInit(&x, MATR_SIZE, 1);
  GetMatrix(&matrix, "matrix-bad.txt");

  ans = Jacobi(matrix, EPS, &T);

  for (i = 0; i < MATR_SIZE; i++)
  {
    printf("%lf\n", ans.matr[i][i]);
    for (j = 0; j < MATR_SIZE; j++)
    {
      x.matr[j][0] = T.matr[j][i];
      printf("%lf ", T.matr[j][i]);
    }
    printf("\n");
    printf("||Lx - Ax||:\n");
    printf("%lf\n\n", GetMatrNorm(Multiplex(Summary(matrix, Alpha(Eye(), ans.matr[i][i]), -1), x)));
  }
  return 0;
}


/*
 * main for leverie
*/
/*
int main(void)
{
  int i, j;
  matrix_t matrix = Eye(), xm;
  poly_t p;
  inter_t iter[MATR_SIZE];
  double x[MATR_SIZE], b[MATR_SIZE] = {EPS};

  GetMatrix(&matrix, "matrix-bad.txt");

  p = Leverie(matrix);

  FindRoots(matrix, p, EPS, iter);

  for (i = 0; i < MATR_SIZE; i++)
  {
    printf("%lf %lf\n", iter[i].a, iter[i].b);

    Solve(Summary(matrix, Alpha(Eye(), iter[i].a), -1), b, x);
    for (j = 0; j < MATR_SIZE; j++)
      printf("%lf ", x[j]);
    xm = VectToMatr(x, MATR_SIZE);
    printf("\n");
    printf("||Lx - Ax||:\n");
    printf("%lf\n\n", GetMatrNorm(Multiplex(Summary(matrix, Alpha(Eye(), iter[i].a), -1), xm)));
  }
  PolyFree(&p);
  return 0;
}
*/

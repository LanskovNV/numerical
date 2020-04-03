#ifndef JACOBI_H
#define JACOBI_H
#include "matrix.h"
/* types */
typedef struct tagPOINT {
  int i;
  int j;
}point_t;
/* functions */
matrix_t Jacobi(matrix_t matrix, double eps, matrix_t *T1);
point_t ChooseElem(matrix_t matrix);
matrix_t GetRotMatr(matrix_t T, point_t p, double c, double s);
#endif // JACOBI_H

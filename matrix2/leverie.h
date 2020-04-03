#ifndef LEVERIE_H
#define LEVERIE_H
#include "matrix.h"
/* types */
typedef struct {
  double a;
  double b;
}inter_t;

typedef struct {
  double *p;
  int pow;
}poly_t;

/* functions */
void PolyInit(poly_t *p, int pow);
void PolyFree(poly_t *p);
poly_t Leverie(matrix_t matrix);
void FindRoots(matrix_t matrix, poly_t p, double eps, inter_t *iter);
#endif // LEVERIE_H

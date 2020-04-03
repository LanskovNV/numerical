#ifndef MATRIX_H
#define MATRIX_H
#define MATR_SIZE 10
/* types */
typedef unsigned int uint;

typedef struct {
  int numOfStrings;
  int numOfVectors;
  double matr[MATR_SIZE][MATR_SIZE];
}matrix_t;

/* source */
void CreateMatrix(matrix_t *good, matrix_t *bad);
void MatrInit(matrix_t *matr, int str, int vect);
void GetMatrix(matrix_t *matrix, char *fileName);
void PutMatrix(matrix_t matrix);

/* translate */
matrix_t VectToMatr(double *vect, int size);
void MatrToVect(matrix_t matr, double *vect);

/* functions */
double GetMatrNorm(matrix_t matrix);
matrix_t Delta(double eps);
matrix_t DeltaVect(double eps);
matrix_t Summary(matrix_t A, matrix_t B, double sign);
matrix_t Trans(matrix_t A);
matrix_t Multiplex(matrix_t A, matrix_t B);
matrix_t Alpha(matrix_t matrix, double alpha);

/* Solve and Inv */
void Solve(matrix_t matrix, double *b, double *x);
matrix_t AntiMatr(matrix_t matrix);

#endif // MATRIX_H

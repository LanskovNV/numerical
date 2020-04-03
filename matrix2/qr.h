/* leins, 13.12.2017 */
#include "matrix.h"
#ifndef QR_H
#define QR_H
matrix_t Qr(matrix_t matrix, double eps);
matrix_t Hessenberg(matrix_t matrix);
matrix_t GetSVect(matrix_t matrix, double L, double eps);
#endif // QR_H

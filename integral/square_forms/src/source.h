#ifndef SOURCE_H
#define SOURCE_H
/* leins, 24.03.2018 */

typedef double func_t(double, double);

double func(double x);
double Runge(double A, double B, double eps, func_t *func);

#endif // SOURCE_H

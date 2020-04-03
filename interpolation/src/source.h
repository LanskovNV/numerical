#pragma once
/* leins, 19.02.2018 */
/* types */
typedef struct {
  char *name;
  double(*func)(double);
  double(*der)(double);
}function_t;

/* functions */
void FuncFree(function_t *func);
void FuncInit(function_t *func, char *name, double(*f)(double), double(*der)(double));
double Func1(double x);
double Func1Der(double x);
double Runge(double x);
double RungeDer(double x);
double TestDer(double x);
double Test(double x);
double FindMaxDelta(double a, double b, double step, double *y, int xLen, function_t f);
double GetW(double a, double b, double step, double xj, int n);
/* leins, 19.02.2018 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "hermith.h"
#include "source.h"
#include "spline3.h"

#define PI 3.14159265358979323846264338327950
#define N 99.

int main(void)
{
  char *fileName = "output.txt";
  //double *diag;
  double *result = NULL, *x = NULL, *knots = NULL;
  double i;
  double step = 0.01;
  int numOfKnots = 0, k, xLen = (int)(((B - A) / step) + 1);
  double inter = (double)((B - A) / N);
  //inter *= 1000000;
  //inter = (double)((int)inter / 1000000.);

  FILE *stream;
  function_t f[2];

  /* init */
  FuncInit(&f[0], "func1", Func1, Func1Der);
  FuncInit(&f[1], "func2", Runge, RungeDer);
  for (i = A; i < B; i += inter) // here was += STEP
    numOfKnots++;

  knots = malloc(sizeof(double) * numOfKnots);
  x = malloc(sizeof(double) * xLen);

  /* init chek */
  if (x == NULL || knots == NULL)
  {
	printf("malloc problem in main\n");
	return 1;
  }

  // ravnomernaya setka
  
  for (i = A, k = 0; i < B; i += inter, k++)
  	knots[k] = i;
  
  // chebyshevskaya setka
  /*
  for (k = 0; k < SIZE / 2; k++)
  {
	double t[SIZE / 2];
	t[k] = cos((2 * k + 1) * PI / SIZE);
	knots[k] = 0.5 * (B + A + (B - A) * t[k]);
  }
  if ((stream = fopen("knots.txt", "w")) == NULL)
  {
	printf("cannot open output file\n");
	return 1;
  }
  else
	for (k = 0; k < SIZE/2; k++)
	  fprintf(stream, "%lf ", knots[k]);
  fclose(stream);
  */
  // x[] gen
  for (i = A, k = 0; k < xLen; i += step, k++)
    x[k] = i;

  /* getting y[] by ermit */
  /*
  diag = BuildDiag(f[0], knots, numOfKnots);
  result = Hermit(x, diag, numOfKnots, xLen, knots);
  */

  /* getting y[] by spline3 */
  
  result = Spline(x, numOfKnots, xLen, knots, f[0]);
  
  /* output in file y[] */
  if ((stream = fopen(fileName, "w")) == NULL)
  {
	printf("cannot open output file\n");
	return 1;
  }
  else
	for (k = 0; k < xLen; k++)
      fprintf(stream, "%lf ", result[k]);
  fclose(stream);

  printf("num of knots: %i\n", numOfKnots); // SIZE / 2
  // N were STEP
  FindMaxDelta(A, B, step, result, xLen, f[0]);
  //printf("|f(x) - P(x)| <= %lf\n", GetW(A, B, N, FindMaxDelta(A, B, step, result, xLen, f[0]), SIZE / 2));

  /* finish */
  //free(diag);
  free(x);
  free(knots);
  free(result);
  
  FuncFree(&f[0]);
  FuncFree(&f[1]);

  getchar();
  return 0;
} /* end of main */

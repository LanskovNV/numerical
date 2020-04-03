/* leins, 19.02.2018 */
#include <stdio.h>
#include <stdlib.h>
#include "hermith.h"
#include "source.h"

static double Delta(double f1, double f2, double x1, double x2, function_t f)
{
  if (x1 == x2)
    return f.der(x1);
  else
    return (f1 - f2) / (x1 - x2);
} /* end of function */
double *BuildDiag(function_t f, double *x, const int numOfKnots)
{
  int size = numOfKnots * 2;
  double *result = malloc(sizeof(double) * size);
  double (*table)[SIZE + 1] = malloc(sizeof(double) * size * (size + 1));
  int i, j, k = 0;

  /* check */
  if (result == NULL || table == NULL)
	return NULL;

  /* table init */
  for (i = 0; i < size; i++)
	for (j = 0; j < size + 1; j++)
	  table[i][j] = 0;

  /* complete two first columns */
  for (i = 0, k = 0; i < size; i++, k++)
  {
	table[i][0] = x[k];
	table[i][1] = f.func(x[k]);
	i++;
	table[i][0] = x[k];
	table[i][1] = f.func(x[k]);
  }

  /* build all table */
  for (i = 2, k = 0; i < size + 1; i++, k++)
  {
    for (j = 1 + k; j < size; j++)
      table[j][i] = Delta(table[j - 1][i - 1], table[j][i - 1], table[j - i + 1][0], table[j - i + 2 + k][0], f);
  }

  /* just for test! */
  /*
  for (i = 0; i < size; i++)
  {
	for (j = 0; j < size + 1; j++)
	  printf("%lf ", table[i][j]);
	printf("\n");
  }
  */
  /* fetch result */
  for (i = 1; i <= size; i++)
	result[i - 1] = table[i - 1][i];

  free(table);
  return result;
} /* end of function */
double *Hermit(double *x, double *y, int numOfKnots, int xLen, double *knots)
{
  int k, i, j;
  double *result = malloc(sizeof(double) * xLen);
  int size = numOfKnots * 2;
  double *z = malloc(sizeof(double) * size);
  
  /* build z */
  for (i = 0, k = 0; i < size; i++, k++)
  {
    z[i++] = knots[k];
    z[i] = knots[k];
  }

  /* build result */
  for (j = 0; j < xLen; j++)
  {
    result[j] = 0;
    for (k = 0; k < size; k++)
    {
      double multi = 1;

      for (i = 0; i < k; i++)
        multi *= (x[j] - z[i]);
	  result[j] += multi * y[k];
    }
  }

  free(z);
  return result;
}

/* leins, 24.03.2018 */
#include <stdio.h>
#include <stdlib.h>
#include "left_square.h"
#include "square_gauss.h"
#include "source.h"

#define A -20 // ������� ���������
#define B 20
#define EPS 0.000001 // ��������� ��������

int main(void)
{
  printf("function: (2 - x^2)*cos(x) + 2*x*sin(x)\n");
  
  printf("Left squares method\n");
  printf("I of %d to %d : %lf \n", A, B, Runge(A, B, EPS, &LeftSquare));
  printf("Gauss method\n");
  printf("I of %d to %d : %lf \n", A, B, Runge(A, B, EPS, &SquareGauss));

  getchar();
  return 0;
} // end of main

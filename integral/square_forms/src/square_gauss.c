/* leins, 24.03.18 */
#include "square_gauss.h"
#include "source.h"

double SquareGauss(double A, double B)
{
  /********************************
   * table walues, do not change!!!
  ********************************/
  int n = 5; // num of knots
  double a[] = { 0.23692688,  0.47862868,  0.56888889,  0.47862868, 0.23692688 }; // koef
  double t[] = {-0.90617985, -0.53846931, 0, 0.53846931, 0.90617985 }; // roots

  int i;
  double res = 0;

  for (i = 0 ; i < n ; i++)
  {
    double tmp = (A + B) / 2 + ((B - A) / 2) * t[i];
    res += a[i] * func(tmp);
  }

  return ((B - A) / 2) * res;
} // end of function

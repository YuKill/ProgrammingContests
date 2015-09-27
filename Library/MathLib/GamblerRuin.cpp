#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double fair_gamblers_ruin(int n1, int n2) {
  return (double)n1/(n1+n2);
}

double unfair_gamblers_ruin(double p, int n1, double q, int n2) {
  if (p == q) return fair_gamblers_ruin(n1, n2);

  double ratio = q/p,
         up    = 1 - pow(ratio, n1),
         down  = 1 - pow(ratio, n1+n2);
  return up/down;
}


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
 
double prob(double i, double n, double p, double q) {
  double probability;
 
  if (p != q)
    probability = (1 - pow(q/p, i)) / (1 - pow(q/p, n));
  else
    probability = i/n;
 
  return probability;
}
 
int main() {
  double ev1, ev2, at, d;
  while (scanf("%lf %lf %lf %lf", &ev1, &ev2, &at, &d) != EOF) {
    if (ev1 == 0 && ev2 == 0 && at == 0 && d == 0) break;
 
    double p = at/6.0, q = 1 - p;
 
    ev1 = ceil(ev1 / d);
    ev2 = ceil(ev2 / d);
 
    double end = prob(ev1, ev1 + ev2, p, q);
 
    printf("%.1f\n", end * 100);
  }
}

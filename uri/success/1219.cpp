#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {

  int a, b, c;

  while (scanf("%d %d %d", &a, &b, &c) != EOF) {
    double a_r, a_v, a_s, a_tri, p, rad;

    p = (a + b + c) / 2.0;
    a_tri = sqrt(p * (p - a) * (p - b) * (p - c));

    rad = (a*b*c) / (4 * a_tri);
    a_s = M_PI * pow(rad, 2);
    a_s -= a_tri;

    rad = a_tri/p;

    a_r = M_PI * pow(rad, 2);
    a_v = a_tri - a_r;

    printf("%.4f %.4f %.4f\n", a_s, a_v, a_r);

  }
}

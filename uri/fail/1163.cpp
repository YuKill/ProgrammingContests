#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>

#define G 9.80665
#define P 3.14159

int main() {
  double h;

  while (scanf("%lf", &h) != EOF) {
    int p1, p2, n, i;

    scanf("%d %d", &p1, &p2);
    scanf("%d", &n);

    double v, alpha;
    for (i = 0; i < n; i++) {
      scanf("%lf %lf", &alpha, &v);
      double gt;
      if (alpha == 90) {
        gt = 0;
      } else {
        double rad = (alpha * P) / 180, cc = cos(rad), t = tan(rad);
        double a = -G/(2*v*v*cc*cc), b = t, c = h;
        double delta = (b*b) - (4*a*c);
        double x1 = (-b + sqrt(delta))/(2*a),
          x2 = (-b - sqrt(delta))/(2*a);

        gt = x1;
        if (x2 > x1) gt = x2;
      }
      printf("%.5f -> ", gt);
      if ((p1 <= gt && gt <= p2)) // || (p1 >= x2 && x2 <= p2))
        printf("DUCK\n");
      else
        printf("NUCK\n");
    }
  }
}

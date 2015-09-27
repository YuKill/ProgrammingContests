#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
  int tests, i;

  scanf("%d", &tests);
  for (i = 0; i < tests; i++) {
    char prob[10001];
    int n, k;
    scanf("%d %s %d", &n, prob, &k);

    long double p = atof(prob), win;
 
    if (p == 1.0 && k == 1)
      win = 1.0;
    else if (p == 1 && k > 1 || p == 0)
      win = 0.0;
    else
      win = -p * pow(1.0-p, k-1) / (pow(1.0-p, n)-1);

    printf("%.4Lf\n", win);
  }
}

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    if (n == 0) break;

    int i, j;
    long long c = 0;
    for (i = 0; i < n; i++) {
      int b;
      scanf("%d", &b);
      c += b * pow(2, i);
    }
    printf("%lld\n", c); 
  }
}

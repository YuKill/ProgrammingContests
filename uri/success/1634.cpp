#include <stdlib.h>
#include <stdio.h>

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  long long n, m;

  while (scanf("%lld %lld", &n, &m) != EOF) {
    if (n == 0 && m == 0) break;

    long long last, sum = 0, t[n];
    int i, j;
    for (i = 0; i < n; i++)
      t[i] = 0;

    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        scanf("%lld", &last);
        if (j == m-1) {
          sum += last;
          t[i] = last;
        }
      }
    }

    for (i = 0; i < n; i++) {
      int factor = gcd(t[i], sum);
      printf("%lld / %lld\n", t[i]/factor, sum/factor);
    }
  }
}

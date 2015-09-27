#include <stdlib.h>
#include <stdio.h>

#define ll long long

int main() {
  ll n;
  while (scanf("%lld", &n) != EOF) {
    if (n == 0) break;

    ll m[n][n], *h, r[n];

    int i, j;
    bool is_homo = true;
    for (i = 0; i < n*n; i++)
      scanf("%lld", &m[i/n][i%n]);

    h = &m[0][0];
    for (i = 1; i < n; i++) {
      r[i] = m[i][0] - h[0];
      for (j = 0; j < n; j++) {
        if (m[i][j] - h[j] != r[i]) {
          is_homo = false;
        }
      }
      if (!is_homo)
        break;
    }
    if (is_homo)
      printf("homogeneous\n");
    else
      printf("not homogeneous\n");
  }
}

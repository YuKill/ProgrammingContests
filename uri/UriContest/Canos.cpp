#include <stdlib.h>
#include <stdio.h>

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int main() {
  int n, t;
  scanf("%d %d", &n, &t);

  int v[n], c[n];
  for (int i = 0; i < n; i++)
    scanf("%d %d", &c[i], &v[i]);

  int m[n+1][t+1];
  for (int i = 0; i <= n; i++) 
    m[i][0] = 0;
  for (int j = 0; j <= t; j++)
    m[0][j] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= t; j++) {
      int k = 1;
      m[i][j] = m[i-1][j];
      while (c[i-1]*k <= j) {
        m[i][j] = max(m[i][j], m[i-1][j-(k*c[i-1])] + (k*v[i-1]));
        k++;
      }
    }
  }

  printf("%d\n", m[n][t]);
}

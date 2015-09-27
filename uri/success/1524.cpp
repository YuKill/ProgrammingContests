#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
  if (a < b) return a;
  else return b;
}

int min_distance(int n, int k, int dist[]) {
  int m[n+1][k+1];

  for (int i = 0; i <= k; i++)
    m[i][i] = 0;
  for (int i = 1; i <= n; i++) {
    m[i][0] = 0;
    m[i][1] = dist[i-1] - dist[0];
  }

  for (int i = 1; i <= n; i++) {
    int max_val = i;
    if (i > k+1) max_val = k+1;
    for (int j = 2; j < max_val; j++) {
      m[i][j] = min(m[i-1][j-1], m[i-1][j] + (dist[i-1] - dist[i-2]));
    }
  }
  return m[n][k];
}


int main() {
  int n, k;
  while (scanf("%d %d", &n, &k) != EOF) {
    int dist[n];
    dist[0] = 0;
    for (int i = 1; i < n; i++) scanf("%d", &dist[i]);
    printf("%d\n", min_distance(n, k, dist));
  }
}

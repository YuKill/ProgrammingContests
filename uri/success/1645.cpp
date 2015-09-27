#include <stdlib.h>
#include <stdio.h>


int main() {
  int n, k;
  while (scanf("%d %d", &n, &k) != EOF) {
    if (n == 0 && k == 0) break;

    int seq[n], a[k];
    for (int i = 0; i < n; i++)
      scanf("%d", &seq[i]);

    unsigned long long m[n][k+1];
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= k; j++)
        m[i][j] = 0;

    for (int i = 0; i < n; i++) {
      m[i][1] = 1;

      int top = i+1;
      if (i+1 > k) top = k;
      for (int j = 2; j <= top; j++) {
        for (int x = 0; x < i; x++) {
          if (seq[i] > seq[x])
            m[i][j] += m[x][j-1];
        }
      }
    }
    
    unsigned long long sum = 0;
    for (int i = 0; i < n; i++) {
      sum += m[i][k];
    }

    printf("%llu\n", sum);
  }
}

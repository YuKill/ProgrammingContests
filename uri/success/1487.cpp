#include <stdlib.h>
#include <stdio.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

int main() {
  for (int n, t, k = 1; scanf("%d %d", &n, &t) != EOF && (n|t); k++) {
    int d[n+1], p[n+1], m[n+1][t+1];
    
    for (int i = 1; i <= n; i++) {
      scanf("%d %d", &d[i], &p[i]);
      m[i][0] = 0;
    }

    for (int i = 0; i <= t; i++)
      m[0][i] = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= t; j++) {
        m[i][j] = m[i-1][j];
        int tms = 1;
        while (tms*d[i] <= j) {
          m[i][j] = max(m[i][j], m[i-1][j-(tms*d[i])] + (tms*p[i]));
          tms++;
        }
      }
    }
    
    printf("Instancia %d\n", k);
    printf("%d\n\n", m[n][t]);
  }
}

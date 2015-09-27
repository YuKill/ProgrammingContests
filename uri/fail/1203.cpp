#include <stdlib.h>
#include <stdio.h>

int main() {
  for (int r, k; scanf("%d %d", &r, &k) != EOF;) {
    bool m[r+1][k+1], bridges_in[r+1];
  
    for (int i = 1; i <= r; i++) bridges_in[i] = 0;
    for (int i = 0, r1, r2; i < k; i++) {
      scanf("%d %d", &r1, &r2);
      bridges_in[r1]++;
      bridges_in[r2]++;
    }

    for (int i = 0; i <= k; i++)
      m[0][i] = false;

    for (int i = 1; i <= r; i++) {
      for (int j = 0; j <= k; j++) {
        m[i][j] = m[i-1][j];
        if (j >= bridges_in[i])
          m[i][j] = m[i][j] || bridges_in[i] == k || m[i-1][j-bridges_in[i]];
      }
    }

    if (m[r][k]) printf("S");
    else printf("N");
    printf("\n");
  }
}

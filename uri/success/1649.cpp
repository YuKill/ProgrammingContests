#include <stdlib.h>
#include <stdio.h>

int main() {
  for (int n, m, r, c; scanf("%d %d %d %d", &n, &m, &r, &c) != EOF && n|m|r|c;) {
    int v[n][m], cnt = 0;
    char bits[n][m+1];

    for (int i = 0; i < n; i++) {
      scanf("%s", bits[i]);
      bits[i][m] = '\0';
      for (int j = 0; j < m; j++) {
        v[i][j] = 0;
      }
    }

    for (int i = 0; i < n-r+1; i++) {
      for (int j = 0; j < m-c+1; j++) {
        if (bits[i][j] - '0' != v[i][j]) {
          for (int p = i; p < i+r; p++) {
            for (int q = j; q < j+c; q++) {
              v[p][q] = (v[p][q] == 0) ? 1 : 0;
            }
          }
          cnt++;
        }
      }
    }

    bool success = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (bits[i][j] - '0'!= v[i][j]) success = false;
      }
    }

    if (success)
      printf("%d\n", cnt);
    else printf("-1\n");
  }
}

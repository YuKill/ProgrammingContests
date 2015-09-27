#include <stdlib.h>
#include <stdio.h>

bool completed(bool *ok, int m) {
  for (int i = 0; i < m; i++)
    if (!ok[i]) return false;
  return true;
}

int main() {
  int m, k;
  while (scanf("%d %d", &m, &k) != EOF) {
    if (m == 0 && k == 0) break;
    int t[m], p[k], i, total = 0;
    bool ok[m];

    for (i = 0; i < m; i++) {
      scanf("%d", &t[i]);
      ok[i] = false;
    }

    for (i = 0; i < k; i++) {
      scanf("%d", &p[i]);
      p[i]--;
    }

    if (k < m) total = -1;
    else {
      for (i = 0; i < k; i++) {
        if (completed(ok, m)) break;
        ok[p[i]] = true;
      }

      if (!completed(ok, m)) total = -1;
      else {
        int n = i;
        for (i = 0; i < n; i++) 
          total += t[p[i]];
      }
    }
    printf("%d\n", total);
  }
}

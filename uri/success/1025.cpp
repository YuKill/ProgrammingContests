#include <stdlib.h>
#include <stdio.h>

int main() {
  for (int n, q, c = 1; scanf("%d %d", &n, &q) != EOF && (n|q); c++) {
    int marble[10001];
    for (int i = 0; i <= 10000; i++) marble[i] = 0;
    for (int i = 1, number; i <= n; i++) {
      scanf("%d", &number);
      marble[number] += 1;
    }
    
    int cnt = 0;
    for (int i = 0; i <= 10000; i++) {
      if (marble[i]) {
        int aux = cnt;
        cnt += marble[i];
        marble[i] = aux + 1;
      }
    }

    printf("CASE# %d:\n", c);
    for (int i = 0, number; i < q; i++) {
      scanf("%d", &number);
      if (marble[number]) printf("%d found at %d\n", number, marble[number]);
      else printf("%d not found\n", number);
    }
  }
}

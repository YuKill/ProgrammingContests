#include <stdlib.h>
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int p[n], sum[n+1];
  sum[0] = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    sum[i+1] = sum[i] + p[i];
  }

  char status;
  scanf("%c", &status);

  int bug;
  while (scanf("%c %d", &status, &bug) != EOF) {
    if (status == 'a')
      for (int i = bug; i <= n; i++)
        sum[i] -= p[bug-1];
    else
      printf("%d\n", sum[bug-1]);

    scanf("%c", &status);
  }
}

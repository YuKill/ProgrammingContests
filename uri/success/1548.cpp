#include <stdlib.h>
#include <stdio.h>

int decr(const void *a, const void *b) {
  return (*(int*)b - *(int*)a);
}

int main() {
  int tests;
  scanf("%d", &tests);

  for (int t = 0; t < tests; t++) {
    int n;
    scanf("%d", &n);

    int score[n], ord[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", &score[i]);
      ord[i] = score[i];
    }

    qsort((void*)&ord[0], n, sizeof(int), decr);

    int cnt = 0;
    for (int i = 0; i < n; i++)
      if (ord[i] == score[i]) cnt++;

    printf("%d\n", cnt);
  }
}

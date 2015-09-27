#include <stdlib.h>
#include <stdio.h>

int main() {
  int test;
  scanf("%d", &test);

  for (int t = 0; t < test; t++) {
    int h[231], n;
    scanf("%d", &n);

    for (int i = 0; i <= 230; i++) h[i] = 0;
    for (int i = 0, tmp; i < n; i++) {
      scanf("%d", &tmp);
      h[tmp]++;
    }

    bool first = true;
    for (int i = 0; i <= 230; i++) {
      if (h[i]) {
        for (int j = 0; j < h[i]; j++) {
          if (!first) printf(" ");
          first = false;
          printf("%d", i);
        }
      }
    }
    printf("\n");
  }
}

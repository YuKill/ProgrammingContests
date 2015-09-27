#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
  int tests;
  scanf("%d", &tests);

  for (int t = 0; t < tests; t++) {
    char a[1024], b[1024];
    scanf("%s %s", a, b);

    int len_a = strlen(a), len_b = strlen(b);
    if (len_a < len_b) printf("nao encaixa\n");
    else {
      int diff = len_a - len_b;
      bool encaixa = true;
      for (int i = len_b-1; i >= 0; i--) {
        if (b[i] != a[i+diff]) {
          encaixa = false;
          break;
        }
      }
      if (encaixa) printf("encaixa\n");
      else printf("nao encaixa\n");
    }
  }
}

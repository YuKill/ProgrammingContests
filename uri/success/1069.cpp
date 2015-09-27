#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
  int tests;
  scanf("%d", &tests);

  for (int t = 0; t < tests; t++) {
    char buf[1024];
    scanf("%s", buf);

    int diamond = 0, len = strlen(buf), sign = 0;
    for (int i = 0; i < len; i++) {
      if (buf[i] == '<') sign++;
      else if (buf[i] == '>' && sign > 0) {
        sign--;
        diamond++;
      }
    }
    printf("%d\n", diamond);
  }
}

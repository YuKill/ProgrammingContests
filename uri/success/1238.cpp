#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
  int tests;
  scanf("%d", &tests);

  for (int t = 0; t < tests; t++) {
    char f[64], b[64];
    scanf("%s %s", f, b);

    int lenf = strlen(f), lenb = strlen(b), len_sml = (lenf < lenb) ? lenf : lenb;
    char *greater = (lenf < lenb) ? b+len_sml : f+len_sml;
    for (int i = 0; i < len_sml; i++)
      printf("%c%c", f[i], b[i]);
    printf("%s\n", greater);
  }
}

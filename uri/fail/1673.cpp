#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NONE 0
#define UNIQ 1
#define REPT 2

int main() {
  for (char s[1024]; scanf("%s", s) != EOF; ) {
    int len = strlen(s), mode = NONE, cnt = 0;
    for (int i = 0; i < len; i++) {
      if (i != len-1 && s[i+1] != s[i] && !cnt) {
        if (mode == NONE) {
          printf("1");
          mode = UNIQ;
        }
        if (s[i] == '1') printf("1");
        printf("%c", s[i]);
      } else if (i != len-1) {
        if (mode == UNIQ) {
          mode = REPT;
          printf("1");
        }
        if (s[i] != s[i+1]) {
          cnt++;
          printf("%d%c", cnt, s[i]);
          cnt = 0;
          mode = NONE;
        } else {
          cnt++;
        }
      } else {
        if (mode == UNIQ)
          printf("%c1", s[i]);
        else if (mode == NONE)
          printf("1%c1", s[i]);
        else if (mode == REPT) {
          printf("%d%c", cnt+1, s[i]);
        }
      }
    }
    printf("\n");
  }
}

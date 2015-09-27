#include <stdlib.h>
#include <stdio.h>

int main() {
  char c;
  while (scanf("%c", &c) != EOF) {
    int p = 0;
    bool correct = true;
    while (c != '\n') {
      if (c == '(') p++;
      else if (c == ')' && p <= 0) correct = false;
      else if (c == ')' && p > 0) p--;
      scanf("%c", &c);
    }
    if (!p && correct) printf("correct\n");
    else printf("incorrect\n");
  }
}

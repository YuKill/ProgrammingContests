#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void to_b(int x, char *s, int fib[]) {
  int cnt = 0;
  for (int i = 21; i >= 0; i--) {
    if (x >= fib[i]) {
      s[cnt++] = '1';
      x -= fib[i];
    } else {
      s[cnt++] = '0';
    }
  }
}

int to_dec(char *s, int fib[]) {
  int begin = 0, num = 0, fn = 21;
  while (s[begin] == '0') { begin++; fn--; }
  fn--;
  for (int i = begin; i < strlen(s)-1; i++) {
    num += ((s[i] - '0') * fib[fn--]);
  }
  return num;
}

int main() {
  int tests;
  scanf("%d", &tests);

  int fib[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657};

  for (int t = 0; t < tests; t++) {
    int x;
    scanf("%d", &x);
    
    char s[30];
    s[22] = '\0';
    to_b(x, s, fib);
    printf("%d\n", to_dec(s, fib));
  }
}

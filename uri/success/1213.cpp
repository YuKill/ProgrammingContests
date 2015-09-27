#include <stdlib.h>
#include <stdio.h>

int main() {

  int n;
  while (scanf("%d", &n) != EOF) {

    long long i = 1 % n;
    int c = 1;
    while (i % n != 0) {
      i = (i * (10 % n)) % n;
      i = (i + 1) % n;
      c++;
    }

    printf("%d\n", c);
  }
}

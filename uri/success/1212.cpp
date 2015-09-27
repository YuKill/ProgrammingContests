#include <stdlib.h>
#include <stdio.h>

#define ull unsigned long long

int main() {
   ull a, b;
  
  while (scanf("%llu %llu", &a, &b) != EOF) {
    if (a == 0 && b == 0) break;

    ull *g = &a, *l = &b, carry = 0;
    int count = 0;

    if (a < b) {
      g = &b;
      l = &a;
    }

    while (*g > 0) {
      if (((*l % 10) + (*g % 10) + carry) > 9) {
        carry = 1;
        count++;
      } else {
        carry = 0;
      }
      *l /= 10;
      *g /= 10;
    }

    if (count == 0)
      printf("No carry operation.\n");
    else if (count == 1)
      printf("1 carry operation.\n");
    else
      printf("%d carry operations.\n", count);

  }
}

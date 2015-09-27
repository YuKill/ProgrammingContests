#include <stdlib.h>
#include <stdio.h>

#define ull unsigned long long

ull gcd(ull a, ull b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  ull x, y, c = 0;

  while (scanf("%llu %llu", &x, &y) != EOF) {
    ull p, q = gcd(x, y);

    p = 2 * x + 2 * y;
    c = p / q;

    printf("%llu\n", c);
  }
}

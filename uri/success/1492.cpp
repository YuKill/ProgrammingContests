#include <stdlib.h>
#include <stdio.h>

#define ull unsigned long long

ull calc_to_n(ull n) {
  ull i, pow2 = 1, c = 0;
  for (i = 0; i < 64; i++) {
    ull q;

    q = (n + 1) / pow2;
    c += (q / 2) * pow2 + ((n + 1) % pow2) * (q % 2);

    if (i != 63)
      pow2 *= 2;
  }
  return c;
}

int main() {
  ull a, b, c = 0;

  while (scanf("%llu %llu", &a, &b) != EOF) {
    c = calc_to_n(b) - calc_to_n(a-1);
    printf("%llu\n", c);
  }
}

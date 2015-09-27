#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long long in_rect(int n, int d, int sq) {
  int i;
  long long sum = 0, comb;

  comb = n * (n + 1) / 2;
  sum = pow(comb, d) - sq;

  return sum;
}

long long in_squares(int n, int d) {
  int i;
  long long sum = 0;
  if (d == 2)
    sum = (n * (n + 1) * (2 * n + 1)) / 6;
  else if (d == 3)
    sum = ((n * n) * (n * n + 2 * n + 1)) / 4;
  else
    sum = (6 * pow(n, 5) + 15 * pow(n, 4) + 10 * pow(n, 3) - n) / 30;

  return sum;
}

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    long long sq2, sq3, sq4;

    sq2 = in_squares(n, 2);
    sq3 = in_squares(n, 3);
    sq4 = in_squares(n, 4);
    printf("%lld %lld %lld %lld %lld %lld\n", sq2, in_rect(n, 2, sq2), sq3, in_rect(n, 3, sq3), sq4, in_rect(n, 4, sq4));
  }
}

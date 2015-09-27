#include <stdlib.h>
#include <stdio.h>

long long discover_sq(long long n) {
  int count = 0, i = 2;
  long long sq = n;

  for (i = 2; i*i <= n; i += 2) {
    count = 0;

    while (n % i == 0) {
      n /= i;
      count++;
    }
    if (count % 2 != 0)
      sq *= i;

    if (i == 2) i--;
  }

  if (n > 1) sq *= n;
  return sq;
}

int main() {
  int t, i;
  scanf("%d", &t);

  for (i = 0; i < t; i++) {
    long long n;
    scanf("%lld", &n);
    printf("Caso #%d: %lld\n", i+1, discover_sq(n));
  }
}

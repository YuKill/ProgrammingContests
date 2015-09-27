#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int find_odd_factors(long long n, int c) {
  long long i;
  int factors = 1;

  while (n % 2 == 0) n = n / 2;
  for (i = 3; i*i <= n; i += 2) {
    int count = 0;

    if (n == 1) break;
    while (n % i == 0) {
      count++;
      n = n / i;
    }

    //printf("%lld - %lld - %d\n", n, i, c);
    factors *= (count + 1);
  }


  if (n > 1) factors *= 2;
  return factors;
}

int main() {
  long long n;
  int c = 1;
  while (scanf("%lld", &n) != EOF) {
    printf("%d\n", find_odd_factors(n, c++));
  }

}

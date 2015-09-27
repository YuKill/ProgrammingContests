#include <stdlib.h>
#include <stdio.h>

int main() {
  long long a,b;
  scanf("%lld %lld", &a, &b);

  a = a-1;
  a = (a*a + a)/2;
  b = (b*b + b)/2;

  printf("%lld\n", b-a);
}

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
  int a,b,q,r;
  scanf("%d %d", &a, &b);

  r = ((a % abs(b)) + abs(b)) % abs(b);
  q = (a-r)/b;

  printf("%d %d\n", q, r);
}

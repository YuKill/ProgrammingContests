#include <stdlib.h>
#include <stdio.h>

void multiply_2x2(int a[][2], int b[][2], int r[][2], int mod) {
  int aux[2][2];
  aux[0][0] = (((a[0][0]%mod)*(b[0][0]%mod))%mod) + (((a[0][1]%mod)*(b[1][0]%mod))%mod);
  aux[0][1] = (((a[0][0]%mod)*(b[0][1]%mod))%mod) + (((a[0][1]%mod)*(b[1][1]%mod))%mod);
  aux[1][0] = (((a[1][0]%mod)*(b[0][0]%mod))%mod) + (((a[1][1]%mod)*(b[1][0]%mod))%mod);
  aux[1][1] = (((a[1][0]%mod)*(b[0][1]%mod))%mod) + (((a[1][1]%mod)*(b[1][1]%mod))%mod);
  r[0][0] = aux[0][0];
  r[0][1] = aux[0][1];
  r[1][0] = aux[1][0];
  r[1][1] = aux[1][1];
}

int fib(int n, int mod) {
  int pw[2][2] = {{1, 1}, {1, 0}}, 
  r[2][2] = {{1, 0}, {0, 1}};

  while (n > 0) {
    if (n & 1) multiply_2x2(r, pw, r, mod);
    multiply_2x2(pw, pw, pw, mod);
    n >>= 1;
  }

  return (r[0][0] + (r[0][0]-1)%mod)%mod;
}

int main() {
  for (int a, b, cnt = 0; scanf("%d %d", &a, &b) != EOF && a|b; cnt++) {
    int f = fib(a, b);
    printf("Case %d: %d %d %d\n", cnt, a, b, f);
  }
}

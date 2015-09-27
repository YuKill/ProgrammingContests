#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define CYCLE 1500
#define MAX 15
#define ll long long

ll n_ato_ull(char *p, int n) {
  ll pow10 = 1, i;
  ll r = 0;
  for (i = n-1; i >= 0; i--) {
    char b[2];
    b[1] = '\0';
    b[0] = p[i];
    r += (pow10 * atoi(b));
    pow10 *= 10;
  }
  return r;
}


int get_mod(char *n) {
  int lenp, mod = 0, len = strlen(n);
  char llint[20], *p = n;
  
  ll nll;
  while (len > 0) {
    int digits = MAX;
    if (len < MAX)
      digits = len;

    nll = n_ato_ull(p, digits);
    p += digits;
    len -= digits;

    if (digits == 15)
      nll = mod * 1000000000000000 + nll;
    else
      nll = mod * pow(10, digits) + nll;
    mod = nll % CYCLE;
  }

  return mod;
}

void fib(int *f) {
  int i;
  f[0] = 0;
  f[1] = 1;
  for (i = 2; i < CYCLE; i++) 
    f[i] = ((f[i-1] % 1000) + (f[i-2] % 1000)) % 1000;
}

int main() {

  int tc, i, f[CYCLE];
  scanf("%d", &tc);
  
  fib(f);

  for (i = 0; i < tc; i++) {
    char buf[2000001];
    int mod;

    scanf("%s", buf);
    
    mod = get_mod(buf);
    if (f[mod] < 100)
      printf("0");
    if (f[mod] < 10)
      printf("0");
    printf("%d\n", f[mod]);
  }
}

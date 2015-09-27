#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int f(int n, int *fac) {
  if (n == 1 || n == 0) 
    fac[n] = 1;
  else
    fac[n] = n * f(n-1, fac);
  return fac[n];
}

int main() {
  char acm[10];
  int fac[6];
  
  f(5, fac);

  while (scanf("%s", acm) != EOF) {
    if (acm[0] == '0') break;
    
    int len = strlen(acm), i, dec = 0;
    for (i = 0; i < len; i++) {
      char buf[2];
      int n;

      buf[1] = '\0';
      buf[0] = acm[i];
      n = atoi(buf);

      //printf("%d = %d - %d - %d\n", dec, n, fac[len-i], len-i);
      dec += n * fac[len-i];
    }

    printf("%d\n", dec);
  }
}

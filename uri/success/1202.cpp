#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 15
#define CYCLE 1500

int p[10001];

int p2(int n) {
  int r, span, i;
  
  span = n/MAX;
  r = int(pow(2, n-span*MAX)) % CYCLE;
  
  for (i = 0; i < span; i++)
    r = (r * (int(pow(2, MAX)) % CYCLE)) % CYCLE;

  p[n] = r;
  return r;
}

int fib(int n) {
  int n1 = 1, n2 = 1, i;
  for (i = 3; i <= n; i++) {
    int f = n1 + n2;
    n2 = n1;
    n1 = f % 1000;
  }
  return n1;
}

int search_p(int n) {
  if (p[n] == 0)
    return p2(n);
  else return p[n];
}

int main() {
   
  int tests, i, j, fb[1501];
  scanf("%d", &tests);

  for (i = 1; i <= CYCLE; i++)
    fb[i] = fib(i);
  
  for (i = 0; i <= 10000; i++)
    p[i] = 0;
  for (i = 0; i < tests; i++) {
    char b[10001];
    scanf("%s", b);

    int len = strlen(b), n = 0;
    for (j = 0; j < len; j++) 
      if (b[j] == '1')
        n += search_p(len-1-j);
    
    int f = fb[n % 1500];
    if (f < 10)
      printf("00");
    else if (f < 100)
      printf("0");
    printf("%d\n", f);
  }
}

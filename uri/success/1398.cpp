#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define NUM 131071
#define MAX 62

int main() {
  char b[10001], buf[101];
  int power[10001], k;

  power[0] = 1;
  for (k = 1; k <= 10000; k++)
    power[k] = (power[k-1] * 2) % NUM;

  while (scanf("%s", buf) != EOF) {
    int len = strlen(buf), i, n = 0;
    char *p = b;

    strcpy(b, buf);
    p += len;
    while (buf[len-1] != '#') {
      scanf("%s", buf);
      len = strlen(buf);
      strcpy(p, buf);
      p += len;
    }

    len = strlen(b);
    b[--len] = '\0';
    for (i = 0; i < len; i++)
      if (b[i] == '1')
        n = (n + (power[len-i-1] % NUM)) % NUM;

    if (n == 0)
      printf("YES\n");
    else
      printf("NO\n");
  }
}

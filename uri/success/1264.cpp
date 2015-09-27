#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long long sum(char *s, long long *gt) {
  long long len = strlen(s), i, final_sum = 0;

  *gt = 0;
  for (i = 0; i < len; i++) {
    long long x;
    if (s[i] < 58)
      x = s[i] - 48;
    else if (s[i] < 91)
      x = s[i] - 55;
    else
      x = s[i] - 61;

    if (x > *gt)
      *gt = x;

    final_sum += x;
  }

  return final_sum;
}

int main() {
  char s[1028];
  while (scanf("%s", s) != EOF) {
    char *start = s;

    while (start[0] == '-') start++;

    long long total, gt, i;
    total = sum(start, &gt);
    if (gt == 0) printf("2\n");
    else {
      bool found = false;
      for (i = gt; i < 62; i++)
        if (total % i == 0) {
          found = true;
          break;
        }
      if (!found) printf("such number is impossible!\n");
      else printf("%lld\n", i+1);
    }
  }
}

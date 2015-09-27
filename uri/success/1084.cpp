#include <stdlib.h>
#include <stdio.h>

bool is_over(int q[], int last) {
  for (int i = 0; i <= last; i++)
    if (q[i] != 0) return false;
  return true;
}

int main() {
  int d, n;
  while (scanf("%d %d", &n, &d) != EOF) {
    if (n == 0 && d == 0) break;
    
    int len = n-d, i = 0;
    char r[len+1], s[n+1];
    bool full = false;

    scanf("%s", s);
    
    s[n] = '\0';
    r[0] = s[0];

    int j;
    for (j = 1; j < n; j++) {
      while (i != -1 && s[j] > r[i] && d) {
        i--; d--;
      }
      i++;
      if (i <= len-1) {
        r[i] = s[j];
      }
    }
    r[len] = '\0';    
    printf("%s\n", r);
  }
}

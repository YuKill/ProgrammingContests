#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int get_nth(char s[][100], int n) {
  int f = 0, p10 = 1;
  for (int i = 3; i >= 0; i--) {
    f += (s[i][n] - '0') * p10;
    p10 *= 10;
  }
  return f;
}

int main() {
  char m[4][100];
  char r[100];

  for (int i = 0; i < 4; i++)
    scanf("%s", m[i]);

  int f = get_nth(m, 0);
  int l = get_nth(m, strlen(m[0])-1);
  
  for (int i = 1; i < strlen(m[i])-1; i++) {
    r[i-1] = ((f*get_nth(m,i)) + l) % 257;
  }
  r[strlen(m[0])-1] = '\0';
  printf("%s\n", r);
}

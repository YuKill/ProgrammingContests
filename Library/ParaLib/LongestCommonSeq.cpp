#include <stdio.h>

int max(int a, int b) {
  return (a > b) ? a : b;
}

int longest_com_seq(int *s1, int *s2, int n, int m) {
  int x[n+1][m+1];
  for (int i = n; i >= 0; i--) {
    for (int j = m; j >= 0; j--) {
      if (i == n || j == m) x[i][j] = 0;
      else if (s1[i] == s2[j]) x[i][j] = x[i+1][j+1] + 1;
      else x[i][j] = max(x[i][j+1], x[i+1][j]);
    }
  }
  return x[0][0];
}


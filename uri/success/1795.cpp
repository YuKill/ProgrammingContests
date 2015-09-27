#include <stdlib.h>
#include <stdio.h>


int main() {
  int l;
  scanf("%d", &l);

  long long t[l+1][l+1];

  for (int i = 0; i <= l; i++) {
    t[i][0] = 1;
    t[i][1] = i;
  }

  for (int i = 2; i <= l; i++) {
    for (int j = 2; j <= i; j++) {     
      t[i][j] = t[i-1][j-1] + t[i-1][j-2];
      if (j == i) t[i][j] += t[i-1][j-2];
      else t[i][j] += t[i-1][j];
    }
  }

  long long sum = 0;
  for (int i = 0; i < l; i++)
    sum += t[l][i];
  sum *= 2;
  sum += t[l][l];

  printf("%lld\n", sum);
}

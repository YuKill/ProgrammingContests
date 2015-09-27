#include <stdlib.h>
#include <stdio.h>

int main() {
  int q, e;
  scanf("%d %d", &q, &e);

  int offices[1001], e_[e];
  for (int i = 0; i < 1000; i++) offices[i] = 1;
  for (int i = 0; i < e; i++) {
    scanf("%d", &e_[i]);
    offices[e_[i]] = 0;
  }

  for (int i = 0; i < q; i++) {
    int lw;
    scanf("%d", &lw);
    printf("%d\n", offices[lw]);
    offices[lw] = 0;
  }


}

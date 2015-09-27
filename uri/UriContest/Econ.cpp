#include <stdlib.h>
#include <stdio.h>

int main() {
  int p;
  scanf("%d", &p);

  int y = 0, n = 0;
  for (int i = 0; i < p; i++) {
    int r;
    scanf("%d", &r);
    if (r) n++;
    else y++;
  }
  if (y > n) printf("Y\n");
  else printf("N\n");
}

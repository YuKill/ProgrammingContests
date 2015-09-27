#include <stdlib.h>
#include <stdio.h>

int main() {
  for (int ang; scanf("%d", &ang) != EOF; ) {
    if (ang % 6) printf("N\n");
    else printf("Y\n");
  }
}

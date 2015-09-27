#include <stdlib.h>
#include <stdio.h>

int main() {
  for (int n; scanf("%d", &n) != EOF && n; ) {
    int total = 0;
    for (int i = 0, comp, qt; i < n; i++) {
      scanf("%d %d", &comp, &qt);
      total += ((qt % 2) ? qt-1 : qt);
    }
    printf("%d\n", total/4);
  }
}

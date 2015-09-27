#include <stdlib.h>
#include <stdio.h>

int main() {
  for (int n, m; scanf("%d %d", &n, &m) != EOF && (n|m); ) {
    int accepted[n], fake = 0;
    for (int i = 0; i < n; i++) accepted[i] = 0;
    for (int i = 0, ticket; i < m; i++) {
      scanf("%d", &ticket);
      if (accepted[ticket-1] == 1) {
        fake++;
        accepted[ticket-1] += 1;
      } else accepted[ticket-1] += 1;
    }

    printf("%d\n", fake);
  }
}

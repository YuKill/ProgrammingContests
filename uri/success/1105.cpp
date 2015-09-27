#include <cstdlib>
#include <cstdio>

int main() {
  for (int b, n; scanf("%d %d", &b, &n) != EOF && b|n; ) {
    int funds[b+1];
    for (int i = 1; i <= b; i++)
      scanf("%d", &funds[i]);

    for (int i = 0; i < n; i++) {
      int d, c, qt;
      scanf("%d %d %d", &d, &c, &qt);
      funds[d] -= qt;
      funds[c] += qt;
    }

    bool success = true;
    for (int i = 1; i <= b; i++)
      if (funds[i] < 0) {
        success = false;
        break;
      }

    if (success) printf("S\n");
    else printf("N\n");
  }
}

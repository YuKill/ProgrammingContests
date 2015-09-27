#include <cstdlib>
#include <cstdio>

int main() {
  for (int n; scanf("%d", &n) != EOF && n;) {
    char ans[] = {'*', 'A', 'B', 'C', 'D', 'E'};
    int mark;
    for (int i = 0; i < n; i++) {
      mark = 0;
      bool ok = true;
      for (int j = 1, gs; j <= 5; j++) {
        scanf("%d", &gs);
        if (ok && gs <= 127) {
          mark = j;
          ok = false;
        } else if (!ok && gs <= 127)
          mark = 0;
      }
      printf("%c\n", ans[mark]);
    }
  }
}

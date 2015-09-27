#include <cstdlib>
#include <cstdio>

#define D 0
#define E 1

#define min(a,b) ((a < b) ? a : b)

int main() {
  for (int n; scanf("%d", &n) != EOF; ) {
    int shoes[61][2];
    for (int i = 30; i <= 60; i++) {
      shoes[i][D] = 0;
      shoes[i][E] = 0;
    }

    for (int i = 0, tam; i < n; i++) {
      char buf[2];
      scanf("%d %s", &tam, buf);
      if (buf[0] == 'D')
        shoes[tam][D]++;
      else
        shoes[tam][E]++;
    }

    int boxes = 0;
    for (int i = 30; i <= 60; i++) {
      boxes += min(shoes[i][D], shoes[i][E]);
    }

    printf("%d\n", boxes);
  }

}

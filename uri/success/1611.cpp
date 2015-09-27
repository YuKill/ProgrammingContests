#include <stdlib.h>
#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 0; i < t; i++) {
    int n, c, m;
    scanf("%d %d %d", &n, &c, &m);

    int dst_floor[m], floor[n+1];
    
    for (int j = 0; j <= n; j++) floor[j] = 0;
    for (int j = 0; j < m; j++) {
      scanf("%d", &dst_floor[j]);
      floor[dst_floor[j]]++;
    }

    int cap = c, energy = 0, top_floor;
    for (int i = n; i >= 0; i--) {
      if (!floor[i]) continue;
      if (cap == c) top_floor = i;
      if (cap >= floor[i]) {
        cap -= floor[i];
        floor[i] = 0;
      } else {
        floor[i] -= cap;
        cap = 0;
      }
      if (!cap) {
        energy += (top_floor*2);
        cap = c;
      }
      if (floor[i]) i++;
    }

    if (cap != c) {
      energy += (top_floor*2);
    }

    printf("%d\n", energy);
  }
}

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct pos {
  int x, y;

  int calc_dist(pos);
  pos &operator=(pos r) {
    x = r.x;
    y = r.y;
    return *this;
  };
} pos;

int pos::calc_dist(pos b) {
  return abs(b.x - x) + abs(b.y - y);
}

int main() {
  int tests;
  scanf("%d", &tests);

  for (int t = 0; t < tests; t++) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    pos pt[n];
    int dist[200001];
    for (int i = 0; i < n; i++)
      scanf("%d %d", &pt[i].x, &pt[i].y); 
    for (int i = 0; i <= 200000; i++)
      dist[i] = 0;

    for (int i = 0; i < m; i++) {
      pos metro;
      scanf("%d %d", &metro.x, &metro.y);
      for (int j = 0; j < n; j++)
          dist[pt[j].calc_dist(metro)]++;
    }

    int sum = 0;
    for (int i = 0; i <= 200000; i++) {
      if (k >= dist[i]) {
        sum += (i * dist[i]);
        k -= dist[i];
      } else {
        sum += (i * k);
        break;
      }
    }
    
    printf("%d\n", sum);
  }
}

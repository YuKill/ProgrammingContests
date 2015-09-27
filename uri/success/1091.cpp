#include <stdlib.h>
#include <stdio.h>

void localize(int n, int m, int x, int y) {
  if (x < n) {
    if (y < m) {
      printf("SO\n");
    } else if (y > m) {
      printf("NO\n");
    }
  } 
  if (x > n) {
    if (y < m) {
      printf("SE\n");
    } else if (y > m) {
      printf("NE\n");
    } 
  }
  if (x == n || y == m) 
    printf("divisa\n");

}

int main() {
  int test;
  int n, m;
  scanf("%d", &test);

  while (test != 0) {
    scanf("%d %d", &n, &m);
    
    int i = 0;
    for (i = 0; i < test; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      localize(n, m, x, y);
    }
    scanf("%d", &test);
  }
}

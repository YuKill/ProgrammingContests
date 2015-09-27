#include <stdlib.h>
#include <stdio.h>

bool clap(int x) {
  int i = x;
  while (i > 6) {
    if (i % 10 == 7)
      return true;
    i = i / 10;
  }
  return (x % 7 == 0);
}

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);

  while (n != 0 && m != 0 && k != 0) {
    int num = m, i = 1;
    
    if (m >= k && clap(num)) k--;
    while (k != 0) {
      if (m == 1 || m == n) {
        num = i * (2 * n - 2) + m;
      } else {
        if (i % 2 == 0) {
          num += (m - 1) * 2; 
        } else {
          num += (n - m) * 2;
        }
      }
      if (clap(num)) k--;
      i++;
    }
    printf("%d\n", num);
    scanf("%d %d %d", &n, &m, &k);
  }
}

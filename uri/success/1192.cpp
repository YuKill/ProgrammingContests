#include <cstdlib>
#include <cstdio>

int main() {
  int tests;
  scanf("%d", &tests);

  for (int t = 0; t < tests; t++) {
    char buf[4];
    scanf("%s", buf);

    int r, n1 = buf[0]-'0', n2 = buf[2]-'0';
    if (n1 == n2) {
      r = n1*n2;
    } else if (buf[1] >= 97) {
      r = n1+n2;
    } else {
      r = n2-n1;
    }
    printf("%d\n", r);
  }
}

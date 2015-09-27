#include <stdlib.h>
#include <stdio.h>

typedef struct fib {
  int rec_calls;
  int result;
  
  void set(int calls, int res) {
    rec_calls = calls;
    result = res;
  };
} fib;

int main() {
  int tests;
  scanf("%d", &tests);

  for (int t = 0; t < tests; t++) {
    int n;
    scanf("%d", &n); 

    fib f[3];
    f[0].set(0, 0);
    f[1].set(0, 1);

    for (int i = 2; i <= n; i++) {
      int calls = f[0].rec_calls + f[1].rec_calls + 2;
      int result = f[0].result + f[1].result;
      f[2].set(calls, result);
      f[0] = f[1];
      f[1] = f[2];
    }

    printf("fib(%d) = %d calls = %d\n", n, f[2].rec_calls, f[2].result);
  }
}

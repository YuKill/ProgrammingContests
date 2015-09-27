#include <stdio.h> 
#include <stdlib.h>

int main() {
  for (int n; scanf("%d", &n) != EOF && n; ) {
    int A[1000001];
    A[0] = 0;
    A[1] = 2;
    A[2] = 3;
    A[3] = 1;
    for (int i = 4; i <= n; i++) {
      if (i % 2) {
        A[i] = A[i-1];
        A[i-1] = i;
      } else {
        A[i] = A[i-2];
        A[i-2] = i;
      }
    }

    for (int i = 1; i <= n; i++) {
      printf("%d", A[i]);
      if (i != n) printf(" ");
    }
    printf("\n");
  }
}

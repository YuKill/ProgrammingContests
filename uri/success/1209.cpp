#include <stdlib.h>
#include <stdio.h>

#define ZERO 99999

bool anyLess(int *d, int np, int k) {
  int i;
  for (i = 0; i < np; i++)
    if (d[i] < k)
      return true;
  return false;
}

int main() {
  int np, nr, k;
  while (scanf("%d %d %d", &np, &nr, &k) != EOF) {
    int adj[np][np];
    int degree[np];
    int i, j;

    //init
    for (i = 0; i < np; i++) {
      degree[i] = 0;
      for (j = 0; j < np; j++)
        adj[i][j] = 0;
    }

    for (i = 0; i < nr; i++) {
      int f1, f2;
      scanf("%d %d", &f1, &f2);
      f1--; f2--;

      degree[f1]++;
      degree[f2]++;

      adj[f1][f2] = 1;
      adj[f2][f1] = 1;
    }

    while (anyLess(degree, np, k)) {
      for (i = 0; i < np; i++) {
        if (degree[i] < k) {
          int d = degree[i];
          degree[i] = ZERO;

          for (j = 0; j < np; j++) {
            if (adj[i][j] == 1) {
              adj[j][i] = 0;
              degree[j]--;
            }
          }
        }
      }
    }

    int count = 0;
    bool hasAnswer = false;
    for (i = 0; i < np; i++) {
      if (degree[i] != ZERO) {
        if (count == 0)
          printf("%d", i+1);
        else
          printf(" %d", i+1);
        count++;
        hasAnswer = true;
      }
    }
    if (!hasAnswer) printf("0");
    printf("\n");
  }
}

#include <stdio.h>

#define ll long long

int main() {
  int R, K;

  while (scanf("%d %d", &R, &K) != EOF) {
    int NofB[R];
    for (int I = 0; I < R; ++I)
      NofB[I] = 0;

    int Map[K+1];
    for (int I = 0; I < K; ++I) {
      int U, V;
      scanf("%d %d", &U, &V);
      ++NofB[U];
      ++NofB[V];
      Map[I] = 0;
    }

    Map[K] = 0;
    Map[0] = 1;
    for (int I = 0; I < R; ++I) {
      for (int J = K; J >= NofB[I]; --J) {
        Map[J] = (Map[J-NofB[I]] & 1) | Map[J];
      }
    }

    if (Map[K]) printf("S\n");
    else printf("N\n");
  }

  return 0;
}

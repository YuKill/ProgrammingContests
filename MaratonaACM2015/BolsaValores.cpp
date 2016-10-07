#include <stdlib.h>
#include <stdio.h>

#include <vector>

#define ull long long

ull Count = 0;

void backtrack(int *V, int C, ull I, ull N, ull *Best, bool *Calculated) {
  if (Calculated[I]) return;
  ++Count;
  Calculated[I] = true;
  for (int K = I+1; K < N; ++K) {
    ull Cost = V[K] - V[I] - C;

    ull PlusCost = 0;
    for (int J = N-2; J > K; --J) {
      backtrack(V, C, J, N, Best, Calculated);
      if (Best[J] > PlusCost) {
        PlusCost = Best[J];
      }
    }
    Cost += PlusCost;

    if (Cost > Best[I])
      Best[I] = Cost;
  }
}

int main() {
  int N, C;
  scanf("%d %d", &N, &C);

  int V[N];
  ull Best[N];
  bool Calculated[N];
  for (int I = 0; I < N; ++I) {
    scanf("%d", &V[I]);
    Best[I] = 0;
    Calculated[I] = false;
  }

  backtrack(V, C, 0, N, Best, Calculated);

  ull Max = 0;
  for (int I = 0; I < N; ++I)
    if (Max < Best[I])
      Max = Best[I];

  printf("%lld\n", Max);
  printf("%lld\n", Count);

}

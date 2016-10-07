#include <stdlib.h>
#include <stdio.h>

#include <vector>

#define ll long long

int main() {
  int N, C;
  scanf("%d %d", &N, &C);

  int V[N];
  for (int I = 0; I < N; ++I) {
    scanf("%d", &V[I]);
  }

  ll MaxLocal = V[0];
  ll MinLocal = V[0];
  ll Sum = 0;
  for (int I = 1; I < N; ++I) {
    if (MaxLocal >= V[I] + C || MinLocal > V[I]) {
      if (MaxLocal - MinLocal - C > 0)
        Sum += MaxLocal - MinLocal - C;
      MaxLocal = V[I];
      MinLocal = V[I];
    } else if (V[I] > MaxLocal) {
      MaxLocal = V[I]; 
    }
  }

  if (MaxLocal - MinLocal - C > 0)
    Sum += MaxLocal - MinLocal - C;

  printf("%lld\n", Sum);

}

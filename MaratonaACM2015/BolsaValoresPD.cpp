#include <stdlib.h>
#include <stdio.h>

#define ll long long int

inline ll Max(ll A, ll B) {
  return (A > B) ? A : B;
}

int main() {
  int N, C;
  scanf("%d %d", &N, &C);

  ll Cost[N];
  ll Earn[N];
  for (int I = 0; I < N; ++I) {
    scanf("%lld", &Cost[I]);
    Earn[I] = 0;
  }

  for (int I = N-2; I >= 0; --I) {
    for (int J = I+1; J < N; ++J) {
      ll NewProfit = Cost[J] - C - Cost[I];
      if (J < N-1) NewProfit += Earn[J+1];
      Earn[I] = Max(Max(Earn[I], NewProfit), Earn[J]);
    }
  }

  printf("%lld\n", Earn[0]);

}

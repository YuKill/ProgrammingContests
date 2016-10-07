#include <stdlib.h>
#include <stdio.h>

#define ll long long int

int main() {
  int N, C;
  scanf("%d %d", &N, &C);

  ll Cost[N];
  for (int I = 0; I < N; ++I) {
    scanf("%lld", &Cost[I]);
  }

  int I = N-1;
  int LocalMax = 0;
  int LocalMin = 0;
  ll Sum = 0;
  bool FromBeginning = true;
  while (I >= 1) {

    if (FromBeginning) {
      while (I >= 1 && Cost[I] <= Cost[I-1])
        --I;

      LocalMax = I;
    }

    --I;
    while (I >= 0 && Cost[I] < Cost[I+1]) {
      if (Cost[I+1] > Cost[LocalMax])
        LocalMax = I+1;
      if (Cost[I] < Cost[LocalMin])
        LocalMin = I;
      --I;
    }

    LocalMin = I+1;

    if (Cost[LocalMax] - Cost[LocalMin] - C > 0) {
      Sum += Cost[LocalMax] - Cost[LocalMin] - C;
      printf("Profit found at %d,%d: %lld\n", LocalMin, LocalMax, Sum);
      FromBeginning = true;
    } else {
      FromBeginning = false; 
    }

  }

  printf("%lld\n", Sum);

}

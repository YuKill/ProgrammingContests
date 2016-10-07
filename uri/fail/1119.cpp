#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

int limit(int F, int N) {
  if (!N) return 0;
  if (F < 0) return abs(F) % N;
  if (F > N-1) return F-N;
  return F;
}

int main() {
  int N, K, M;
  while (scanf("%d %d %d", &N, &K, &M) && (N | K | M)) {
    int F1 = 0, F2 = N-1;
    vector<int> Ring;

    for (int I = 1; I <= N; ++I)
      Ring.push_back(I);


    while (!Ring.empty()) {
      int K_ = K-1, M_ = M-1, Size = Ring.size();

      while (K_) {
        F1 = limit(F1+1, Size); 
        --K_;
      }

      while (M_) {
        F2 = limit(F2-1, Size); 
        --M_;
      }

      printf("%03d ", Ring[F1]);
      if (Size != 1)
        printf(", ");
      if (F1 != F2) {
        printf("%03d", Ring[F2]);
        if (Size != 1)
          printf(", ");
      }

      if (F1 > F2) {
        Ring.erase(Ring.begin() + F1);
        Ring.erase(Ring.begin() + F2);
        F1 = limit(F1-1, Ring.size());
        F2 = limit(F2-1, Ring.size());
      } else if (F2 > F1) {
        Ring.erase(Ring.begin() + F2);
        Ring.erase(Ring.begin() + F1);
        F2 = limit(F2-2, Ring.size());
      } else {
        Ring.erase(Ring.begin() + F1);
        F1 = limit(F1, Ring.size());
        F2 = limit(F2, Ring.size());
      }
    }
    printf("\n");
  }
}

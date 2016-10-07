#include <iostream>
#include <limits.h>

using namespace std;

inline unsigned max(unsigned A, unsigned B) {
  return (A > B) ? A : B;
}

inline unsigned min(unsigned A, unsigned B) {
  return (A < B) ? A : B;
}

int main() {
  unsigned N, K;

  while (cin >> N >> K && (N|K)) {
    unsigned Min = N;
    unsigned Max = N;

    for (int I = 0; I < K; ++I) {
      int A, B;
      cin >> A >> B;

      unsigned BitA, BitB;
      BitA = ((1 << A) & N);
      BitB = ((1 << B) & N);

      N -= BitA;
      N -= BitB;

      N += ((BitA >> A) << B);
      N += ((BitB >> B) << A);

      Min = min(Min, N);
      Max = max(Max, N);
    }

    cout << N << " " << Max << " " << Min << endl;
  }
}

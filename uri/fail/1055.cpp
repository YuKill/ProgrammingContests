#include <iostream>
#include <deque>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  int T;
  cin >> T;

  for (int I = 0; I < T; ++I) {
    int N;
    cin >> N;

    vector<int> V(N, 0);
    for (int J = 0; J < N; ++J)
      cin >> V[J];

    sort(V.begin(), V.end(), less<int>());

    deque<int> Best;
    int L = 0, G = V.size()-1;
    Best.push_back(V[G--]);

    while (true) {
      if (L <= G) Best.push_front(V[L++]);
      else break;
      if (L <= G) Best.push_back(V[L++]);
      else break;
      if (L <= G) Best.push_front(V[G--]);
      else break;
      if (L <= G) Best.push_back(V[G--]);
      else break;
    }

    ll Sum = 0;
    for (int J = 1; J < N; ++J)
      Sum += abs(Best[J-1] - Best[J]);

    cout << "Case #" << I+1 << ": " << Sum << endl;
  }

  return 0;
}

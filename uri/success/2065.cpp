#include <iostream>
#include <queue>
#include <set>
#include <limits.h>

using namespace std;

inline int min(int A, int B) {
  return (A < B) ? A : B;
}

int main() {
  int N, M;
  cin >> N >> M;

  int Time[N];
  int ETime[N];
  for (int I = 0; I < N; ++I) {
    cin >> Time[I];
    ETime[I] = 0;
  }

  queue<int> Queue;
  for (int I = 0, Items; I < M; ++I) {
    cin >> Items;
    Queue.push(Items);
  }

  unsigned long long Total = 0;
  while (true) {
    int Min = INT_MAX;
    for (int I = 0; I < N; ++I) {
      if (!ETime[I] && !Queue.empty()) {
        int Items = Queue.front();
        ETime[I] = Time[I] * Items;
        Queue.pop();
      }

      if (ETime[I])
        Min = min(Min, ETime[I]);
    }

    if (Min == INT_MAX)
      break;

    for (int I = 0; I < N; ++I)
      if (ETime[I])
        ETime[I] -= Min;  

    Total += Min;
  }

  cout << Total << endl;
}

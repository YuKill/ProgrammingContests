#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<vector<int> > > MapType;

int N;
int Size[3];
vector<int> Deck[3];
MapType Map;

int top(int Idx) {
  return Deck[Idx][N - Size[Idx]];
}

int getMap() {
  return Map[Size[0]][Size[1]][Size[2]];
}

void setMap(int X) {
  Map[Size[0]][Size[1]][Size[2]] = X;
}

int canWin() {
  int Ans = getMap();
  if (!Ans) return 0;
  else if (Ans == 1) return 1;

  if (!Size[0] && !Size[1] && !Size[2]) return 1;

  if (Size[0] && top(0) % 3 == 0) {
    Size[0]--;
    setMap(canWin());
    if (getMap()) return 1;
    Size[0]++;
  }

  if (Size[1] && top(1) % 3 == 0) {
    Size[1]--;
    setMap(canWin());
    if (getMap()) return 1;
    Size[1]++;
  }

  if (Size[2] && top(2) % 3 == 0) {
    Size[2]--;
    setMap(canWin());
    if (getMap()) return 1;
    Size[2]++;
  }

  if (Size[0] && Size[1] && (top(0) + top(1)) % 3 == 0) {
    Size[0]--; Size[1]--;
    setMap(canWin());
    if (getMap()) return 1;
    Size[0]++; Size[1]++;
  }

  if (Size[0] && Size[1] && Size[2] && (top(0) + top(1) + top(2)) % 3 == 0) {
    Size[0]--; Size[1]--; Size[2]--;
    setMap(canWin());
    if (getMap()) return 1;
    Size[0]++; Size[1]++; Size[2]++;
  }

  if (Size[1] && Size[2] && (top(1) + top(2)) % 3 == 0) {
    Size[1]--; Size[2]--;
    setMap(canWin());
    if (getMap()) return 1;
    Size[1]++; Size[2]++;
  }

  if (Size[0] && Size[2] && (top(0) + top(2)) % 3 == 0) {
    Size[0]--; Size[2]--;
    setMap(canWin());
    if (getMap()) return 1;
    Size[0]++; Size[2]++;
  }

  return 0;
}

int main() {
  while (cin >> N && N) {
    Map.assign(N+1, vector<vector<int> >(N+1, vector<int>(N+1, -1)));

    for (int I = 0; I < 3; ++I) {
      Size[I] = N;
      Deck[I].assign(N, 0);
    }

    for (int I = 0; I < N; ++I) {
      for (int J = 0; J < 3; ++J)
        cin >> Deck[J][I];
    }

    cout << canWin() << endl;

  }

  return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool match(string S1, string Match) {
  return true;
}

bool isPrefix(vector<string> List) {
  int N = List.size();
  bool IsPrefix = true;
  for (int X = 0; X < N; ++X) {
    for (int Y = 0; Y < X; ++Y) {
      if (X == Y) continue; 
      IsPrefix = true;
      bool IsGreater = (List[X].length() > List[Y].length());
      string &S = (IsGreater) ? List[X] : List[Y];
      string &M = (IsGreater) ? List[Y] : List[X];

      for (int I = 0; I < M.length(); ++I)
        if (S[I] != M[I]) {
          IsPrefix = false; 
          break;
        }

      if (IsPrefix) return true;
    } 
  }
  return false;
}

int main() {
  int T;
  cin >> T;
  for (int I = 0; I < T; ++I) {
    int N;
    cin >> N;

    vector<string> List(N, "");
    for (int J = 0; J < N; ++J) {
      cin >> List[J]; 
    }

    if (isPrefix(List)) cout << "NO" << endl;
    else cout << "YES" << endl;
  }
}

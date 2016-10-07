#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define WHT 0
#define GRY 1
#define BLK 2

typedef long long ll;
typedef vector<int> vi;
    
struct DfsPack {
  int V;
  int Finish;
  int Color;
};

void dfs(int U, int &Cur, vector<DfsPack> &Props, vector<vi> &Deps) {
  ++Cur;
  Props[U].Color = GRY;
  for (int Vi = 0, E = Deps[U].size(); Vi < E; ++Vi) {
    if (Props[Deps[U][Vi]].Color == WHT) {
      dfs(Deps[U][Vi], Cur, Props, Deps);
    }
  }
  Props[U].Color = BLK;
  Props[U].Finish = Cur;
  ++Cur;
}

bool byFinish(DfsPack One, DfsPack Two) {
  return One.Finish < Two.Finish;
}

int main() {
  int T;
  cin >> T;

  for (int Ti = 0; Ti < T; ++Ti) {
    int N, M;
    cin >> N >> M;

    vector<vi> Deps;
    Deps.assign(N, vector<int>());
    for (int Mi = 0; Mi < M; ++Mi) {
      int U, V; 
      cin >> U >> V;
      Deps[U-1].push_back(V-1);
    }

    int Cur = 0;
    vector<DfsPack> Props, IProps;
    for (int I = 0; I < N; ++I) {
      Props.push_back({ I, 0, WHT });
      IProps.push_back({ I, 0, WHT });
    }

    for (int I = 0; I < N; ++I) {
      if (Props[I].Color == WHT) {
        dfs(I, Cur, Props, Deps);
      }
    }

    sort(Props.begin(), Props.end(), byFinish);

    /*
    vector<vi> IDeps(N, vector<int>());
    for (int I = 0; I < N; ++I)
      for (int J = 0, E = Deps[I].size(); J < E; ++J)
        IDeps[Deps[I][J]].push_back(I);
    */

    int SCCs = 0;

    for (int I = 0; I < N; ++I) {
      int V = Props[I].V;
      if (IProps[V].Color == WHT) {
        dfs(V, Cur, IProps, Deps); 
        ++SCCs;
      }
    }

    if (SCCs < N) cout << "SIM" << endl;
    else cout << "NAO" << endl;

  }

  return 0;
}

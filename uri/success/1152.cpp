#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct Edge {
  int U, V, Cost;
};

struct Vertex {
  int V;
  int Conn;
  int Cost;
};

struct Index {
  int I;
  int *CostRef;
};

struct TreeIdx {
  int Size;
  int Parent;
};

typedef long long ll;
typedef vector<Edge> VEdge;

bool costCompare(Edge One, Edge Two) {
  return One.Cost > Two.Cost;
}

int findRoot(vector<int> &TreeParent, int X) {
  if (TreeParent[X] != X) {
    TreeParent[X] = findRoot(TreeParent, TreeParent[X]); 
  }
  return TreeParent[X];
}

int main() {
  int N, M;

  while (cin >> N >> M && (N || M)) {
    ll Total = 0;

    vector<Edge> Edges;
    for (int Mi = 0; Mi < M; ++Mi) {
      int U, V, W;

      cin >> U >> V >> W;

      Edges.push_back({ U, V, W });

      Total += W;
    }

    sort(Edges.begin(), Edges.end(), costCompare);

    vector<int> TreeParent;
    for (int I = 0; I < N; ++I)
      TreeParent.push_back(I);

    ll Cost = 0;
    while (!Edges.empty()) {
      Edge E = Edges.back();
      Edges.pop_back();

      int RootU = findRoot(TreeParent, E.U);
      int RootV = findRoot(TreeParent, E.V);
      if (RootV != RootU) {
        TreeParent[RootU] = RootV;
        TreeParent[E.U] = RootV;
        Cost += E.Cost;
      }
    }

    cout << Total - Cost << endl;
  }

  return 0;
}

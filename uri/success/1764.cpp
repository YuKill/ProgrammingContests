#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

struct Edge {
  int u, v, w;
};

int findRoot(vector<int> parents, int i) {
  int oldI = i;
  while (parents[i] != i) {
    i = parents[i];
  }
  parents[oldI] = i;
  return parents[i];
}

bool wCompare(Edge one, Edge two) {
  return one.w < two.w;
}

int main() {
  int n, m;

  while (cin >> n >> m && (n || m)) {
    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      edges.push_back({ u, v, w });
    }

    sort(edges.begin(), edges.end(), wCompare);

    vector<int> parents;
    for (int i = 0; i < n; ++i)
      parents.push_back(i);

    ll total = 0;
    for (int i = 0; i < m; ++i) {
      Edge e = edges[i];

      int rootU = findRoot(parents, e.u);
      int rootV = findRoot(parents, e.v);
      if (rootV != rootU) {
        parents[e.v] = rootU;
        parents[rootV] = rootU;
        total += e.w;
      }
    }

    cout << total << endl;
  }

  return 0;
}

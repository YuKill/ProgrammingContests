#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

struct Edge {
  int u, v;
};

int findRoot(vector<int> parents, int i) {
  int old = i;
  while (parents[i] != i) {
    i = parents[i];
  }
  parents[old] = i;
  return i;
}

int main() {
  int t;
  cin >> t;

  for (int tI = 0; tI < t; ++tI) {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      edges.push_back({ u, v });
    }

    vector<int> parents;
    for (int i = 0; i < n; ++i)
      parents.push_back(i);

    for (int i = 0; i < m; ++i) {
      Edge e = edges[i];

      int rootU = findRoot(parents, e.u);
      int rootV = findRoot(parents, e.v);
      if (rootV != rootU) {
        parents[e.v] = rootU;
        parents[rootV] = rootU;
      }
    }

    int count = 0;
    vector<int> trees(n, 0);
    for (int i = 0; i < n; ++i) {
      int root = findRoot(parents, i); 
      if (!trees[root]) ++count;
      ++trees[root];
    }

    cout << "Caso #" << tI+1 << ": ";
    if (count-1 == 0) cout << "a promessa foi cumprida";
    else cout << "ainda falta(m) " << count-1 << " estrada(s)";
    cout << endl;
  }

  return 0;
}

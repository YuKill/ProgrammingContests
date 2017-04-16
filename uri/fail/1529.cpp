
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

#define inf INT_MAX
#define WHT 0
#define BLK 1

#define sum(x, y) (((x) == inf || (y) == inf) ? inf : (x) + (y))

struct edge_t {
    int v;
    int w;

    edge_t() : edge_t(0, 0) {}
    edge_t(int v, int w) : v(v), w(w) {}
};

struct vert_t {
    int v;
    int dist;

    vert_t(int v, int d) : v(v), dist(d) {}
};

struct comp_t {
    bool operator()(const vert_t &lhs, const vert_t &rhs) {
        return lhs.dist >= rhs.dist;
    }
};

int backtrack(int u, int t, int *visited, vector< vector<edge_t> > &adj, vector< vector<int> > &dyn, vector<int> &cost) {

    for (int k = 0; k <= t; ++k) {
        int r = dyn[u][k];
        for (int i = 0, e = adj[u].size(); i < e; ++i) {
            int v = adj[u][i].v;
            int w = adj[u][i].w;

            int old = min(t, k + w);
            int gasCost = (k - old + w) * cost[u];

            r = min(r, sum(dyn[v][old], gasCost));
        }

        int lesser = 0;
        for (int i = 0; i < k; ++i)
            lesser = (dyn[u][lesser] > dyn[u][i]) ? i : lesser;

        dyn[u][k] = min(r, sum(dyn[u][lesser], (k - lesser) * cost[u]));
    }

    visited[u] = 1;
    for (int i = 0, e = adj[u].size(); i < e; ++i) {
        int v = adj[u][i].v;

        if (!visited[v])
            backtrack(v, t, visited, adj, dyn, cost);
    }
    visited[u] = 0;

    return 0;
}

int main() {

    for (int n, m, t; cin >> n >> m >> t && (n | m | t);) {
        vector< vector<edge_t> > adj(n, vector<edge_t>());

        for (int i = 0, u, v, c; i < m; ++i) {
            cin >> u >> v >> c;
            --u; --v;
            adj[u].push_back(edge_t(v, c));
            adj[v].push_back(edge_t(u, c));
        }

        vector<int> cost(n, 0);
        for (int i = 0; i < n; ++i)
            cin >> cost[i];

        vector< vector<int> > dyn(n, vector<int>(t+1, inf));
        for (int j = 0; j <= t; ++j)
            dyn[0][j] = 0;

        int visited[n];
        memset(visited, 0, n * sizeof(int));

        visited[0] = 1;
        backtrack(0, t, visited, adj, dyn, cost);

        int eco = inf;
        for (int i = 0; i <= t; ++i) {
            eco = min(eco, dyn[n-1][i]);
        }

        if (eco == inf) cout << "-1" << endl;
        else cout << eco << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

#define ALF 26

struct edge_t {
    int v;
    unsigned com;

    edge_t() : edge_t(0, 0) {
    }

    edge_t(int v, int c) : v(v), com(c) {
    }
};

inline void print(int v) {
    bool hasAny = false;
    for (int i = 0; i < ALF; ++i)
        if (v >> i & 1) {
            cout << (char)('a' + i);
            hasAny = true;
        }

    if (!hasAny) cout << "-";
    cout << endl;
}

int main() {

    for (int n; cin >> n && n;) {
        vector< vector<edge_t> > adj(n, vector<edge_t>());

        for (int u, v; cin >> u >> v && u|v;) {
            string comS;
            cin >> comS;

            --u;
            --v;

            unsigned com = 0;
            for (int i = 0, e = comS.length(); i < e; ++i)
                com = com | (1 << (comS[i] - 'a'));

            edge_t edge(v, com);
            adj[u].push_back(edge);
        }

        unsigned floyd[n][n];
        memset(floyd, 0, n*n*4);

        for (int i = 0; i < n; ++i) {
            int u = i;
            for (int j = 0, e = adj[u].size(); j < e; ++j) {
                edge_t edge = adj[u][j];
                floyd[u][edge.v] = edge.com;
            }
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (i == k) continue;
                for (int j = 0; j < n; ++j) {
                    if (j == i || j == k) continue;
                    floyd[i][j] = floyd[i][j] | (floyd[i][k] & floyd[k][j]);
                }
            }
        }

        for (int u, v; cin >> u >> v && u|v;) {
            print(floyd[--u][--v]);
        }

        cout << endl;
    }

    return 0;
}

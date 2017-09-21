#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

vector<bool> visited;
vector<ull> debt;
vector<vector<pair<ull, ull>>> adj;

ull n, c;

ull dfs(ull i) {
    visited[i] = true;

    ull mindist = 0;
    for (auto p : adj[i]) {
        if (!visited[p.first]) {
            ull mindist_ = dfs(p.first);

            mindist += (ceil((double) debt[p.first] / (double) c) * p.second * 2) + mindist_;
            debt[i] += debt[p.first];
        }
    }

    return mindist;
}

int main() {
    cin >> n >> c;

    visited.assign(n, false);
    debt.assign(n, 0);
    adj.assign(n, vector<pair<ull, ull>>());

    for (int i = 0; i < n; ++i)
        cin >> debt[i];

    ull a, b, dist;
    while (cin >> a >> b >> dist) {
        --a; --b;
        adj[a].push_back(make_pair(b, dist));
        adj[b].push_back(make_pair(a, dist));
    }

    ull mindist = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            mindist += dfs(i);
        }
    }

    cout << mindist << endl;

    return 0;
}

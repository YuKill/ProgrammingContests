#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_set>

using namespace std;

inline vector<int> setInters(int n, unordered_set<int> &k, unordered_set<int> &r) {
    int v[n];
    memset(v, 0, n * sizeof(int));

    for (unordered_set<int>::iterator it = k.begin(), e = k.end(); it != e; ++it)
        v[*it] += 1;

    for (unordered_set<int>::iterator it = r.begin(), e = r.end(); it != e; ++it)
        v[*it] += 1;

    vector<int> result;
    for (int i = 0; i < n; ++i)
        if (v[i] == 2) result.push_back(i);

    return result;
}

int main() {

    for (int n, m; cin >> n >> m;) {
        vector< vector<int> > adj(n, vector<int>());

        for (int i = 0, u, v; i < m; ++i) {
            cin >> u >> v;
            --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector< vector<int> > keysLoc(n, vector<int>());
        for (int i = 1, k; i < n; ++i) {
            cin >> k;
            keysLoc[--k].push_back(i);
        }

        unordered_set<int> keys, reachable, visited;

        keys.insert(0);
        reachable.insert(0);

        vector<int> intersect;
        while (!(intersect = setInters(n, keys, reachable)).empty()) {
            for (int v : intersect) {
                keys.erase(keys.find(v));
                reachable.erase(reachable.find(v));

                visited.insert(v);

                for (int i = 0, e = keysLoc[v].size(); i < e; ++i)
                    keys.insert(keysLoc[v][i]);
                for (int i = 0, e = adj[v].size(); i < e; ++i)
                    reachable.insert(adj[v][i]);
            }

        }

        if (visited.size() < n) cout << "nao" << endl;
        else cout << "sim" << endl;
    }

    return 0;
}

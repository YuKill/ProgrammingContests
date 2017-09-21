#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <map>
#include <queue>

using namespace std;

#define SIZE 8
#define inf -1

struct DjComp {
    bool operator()(const pair<int, int>& l, const pair<int, int>& r) {
        if (l.first != r.first) return l.first > r.first;
        return l.second > r.second;
    }
};

struct Comp {
    bool operator()(const vector<int>& l, const vector<int>& r) {
        for (int i = 0; i < SIZE; ++i)
            if (l[i] != r[i]) return l[i] < r[i];
        return false;
    }
};

void printv(vector<int>& v) {
    cout << "[";
    for (int i = 0; i < SIZE; ++i)
        cout << " " << v[i];
    cout << " ]" << endl;
}

int main() {
    vector<int> init(SIZE, 0);
    vector<int> fin(SIZE, 0);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> init[i*4 + j];
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> fin[i*4 + j];
        }
    }

    map<vector<int>, int, Comp> M;
    vector<vector<int>> m(40320, vector<int>());

    vector<int> dist;
    vector<bool> visited;
    priority_queue<pair<int, int>, vector<pair<int, int>>, DjComp> q;

    int id = 0;

    M[init] = id;
    m[id] = init;

    dist.push_back(0);
    visited.push_back(false);
    q.push(pair<int, int>( 0, id ));
    while (!q.empty()) {
        auto curpair = q.top();
        q.pop();

        int curd = curpair.first;
        int cur = curpair.second;

        if (visited[cur]) continue;
        visited[cur] = true;

        auto vcur = m[cur];

        // cout << "dist:" << curd << " ";
        // printv(vcur);

        // Check
        bool found = true;
        for (int i = 0; i < SIZE; ++i) {
            if (fin[i] != vcur[i]) {
                found = false;
                break;
            }
        }

        if (found) break;

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                vector<int> cpy = vcur;
                std::swap(cpy[i*4 + j], cpy[i*4 + j+1]);
                
                int newc = curd + cpy[i*4 + j] + cpy[i*4 + j+1];

                int cpyid;
                auto it = M.find(cpy);
                if (it == M.end()) {
                    cpyid = ++id;

                    M[cpy] = cpyid;
                    m[id] = cpy;
                    q.push(pair<int, int>(newc, cpyid));

                    visited.push_back(false);
                    dist.push_back(newc);
                    // cout << "[new]";
                } else {
                    cpyid = M[cpy];

                    if (newc < dist[cpyid]) {
                        dist[cpyid] = newc;
                        q.push(pair<int, int>(newc, cpyid));
                    }
                }

                // cout << "\tdist:" << dist[cpyid] << " ";
                // printv(cpy);
            }
        }

        for (int i = 0; i < 4; ++i) {
            vector<int> cpy = vcur;
            std::swap(cpy[i], cpy[i + 4]);

            int newc = curd + cpy[i] + cpy[i + 4];

            int cpyid;
            auto it = M.find(cpy);
            if (it == M.end()) {
                cpyid = ++id;

                M[cpy] = cpyid;
                m[id] = cpy;
                q.push(pair<int, int>(newc, cpyid));

                visited.push_back(false);
                dist.push_back(newc);
                // cout << "[new]";
            } else {
                cpyid = M[cpy];

                if (newc < dist[cpyid]) {
                    dist[cpyid] = newc;
                    q.push(pair<int, int>(newc, cpyid));
                }
            }

            // cout << "\tdist:" << dist[cpyid] << " ";
            // printv(cpy);
        }
    }

    cout << dist[M[fin]] << endl;
}

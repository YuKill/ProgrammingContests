#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

inline int step(int n, int pos, int steps) {
    if (!n) return 0;

    int dest = pos + steps;
    if (dest >= n) return dest % n;
    if (dest < 0) return (n - (abs(dest) % n)) % n;
    return dest;
}

inline void print(int i) {
    cout << setfill(' ') << setw(3) << i+1;
}

int main() {
    for (int n, k, m; cin >> n >> k >> m && n|k|m;) {
        vector<int> ring(n, 0);
        for (int i = 0; i < n; ++i)
            ring[i] = i;

        --k;
        --m;
        m = -m;

        int ki = 0, mi = n-1, counter = n;

        while (counter) {
            int _n = ring.size();
            ki = step(_n, ki, k);
            mi = step(_n, mi, m);

            int removed = 0;
            if (mi == ki) {
                print(ring[mi]);
                ring.erase(ring.begin() + mi);

                _n = ring.size();
                mi = step(_n, mi, -1);
                ki = step(_n, ki, 0);

                ++removed;
            } else {
                print(ring[ki]);
                print(ring[mi]);

                int greater = max(mi, ki), lesser = min(mi, ki);
                ring.erase(ring.begin() + greater);
                ring.erase(ring.begin() + lesser);

                _n = ring.size();
                if (_n && mi > ki) mi = step(_n, mi, -2);
                else if (_n) {
                    ki = step(_n, ki, -1);
                    mi = step(_n, mi, -1);
                }

                ++removed;
                ++removed;
            }

            counter -= removed;
            if (counter) cout << ",";
        }

        cout << endl;
    }
    return 0;
}

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
#include <limits>

using namespace std;

const double dbl_inf = numeric_limits<double>::infinity();

struct Coord {
    int x, y;
};

double dist(const Coord& lhs, const Coord& rhs) {
    return sqrt(((lhs.x - rhs.x) * (lhs.x - rhs.x)) +
            ((lhs.y - rhs.y) * (lhs.y - rhs.y)));
}

int main() {
    cout << std::fixed << std::setprecision(5);

    int n, k;
    cin >> n >> k;

    vector<Coord> cities(n);
    vector<vector<double>> d(n, vector<double>(n, dbl_inf));

    for (int i = 0; i < n; ++i) {
        cin >> cities[i].x >> cities[i].y;
    }

    for (int i = 0; i < n; ++i) {
        d[i][i] = 0;

        for (int j = k; j < n; ++j) {
            d[i][j] = d[j][i] = dist(cities[i], cities[j]);
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    double minCost[n][1 << k];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (1 << k); ++j) {
            minCost[i][j] = dbl_inf;
        }

        if (i < k) minCost[i][1 << i] = 0;
    }

    for (int mask = 0; mask < (1 << k); ++mask) {
        for (int i = 0; i < n; ++i) {
            for (int smask = mask; smask > 0; smask = (smask - 1) & mask) {
                minCost[i][mask] = min(minCost[i][mask],
                        minCost[i][smask] + minCost[i][mask - smask]);
            }

            if (!isinf(minCost[i][mask])) {
                for (int j = k; j < n; ++j) {
                    minCost[j][mask] = min(minCost[j][mask], minCost[i][mask] + d[i][j]);
                }
            }
        }
    }

    double sTree = dbl_inf;
    for (int i = k; i < n; ++i) {
        sTree = min(sTree, minCost[i][(1 << k) - 1]);
    }

    cout << sTree << endl;
    return 0;
}

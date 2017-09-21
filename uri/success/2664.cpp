#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

#define M 1000000007

int main() {
    ull t, m, n;
    cin >> t >> m >> n;

    ull val = n - m + 1;

    vector<vector<ull>> mat(val, vector<ull>(t, 0));

    for (int i = 0; i < val; ++i)
        mat[i][0] = 1;

    for (int j = 1; j < t; ++j) {
        for (int i = 0; i < val; ++i) {
            mat[i][j] = 0;

            if (i > 0)
                mat[i][j] = (mat[i][j] + mat[i-1][j-1]);
            if (i < val-1)
                mat[i][j] = (mat[i][j] + mat[i+1][j-1]) % M;
        }
    }

    ull sum = 0;
    for (int i = 0; i < val; ++i)
        sum = (sum + mat[i][t-1]) % M;
    cout << sum << endl;
    return 0;
}

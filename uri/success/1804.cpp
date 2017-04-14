
#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int v[n], sum[n + 1];

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum[i] = 0;
    }
    sum[n] = 0;

    for (int i = 1; i <= n; ++i) {
        int x = i;
        while (x <= n) {
            sum[x] += v[i-1];
            x += (x & -x);
        }
    }

    char c;
    int i;
    for (; cin >> c >> i;) {
        switch (c) {
            case 'a':
                {
                    int x = i;
                    while (x <= n) {
                        sum[x] -= v[i-1];
                        x += (x & -x);
                    }
                    break;
                }

            case '?':
                {
                    int x = i;
                    int acc = 0;
                    while (x > 0) {
                        acc += sum[x];
                        x -= (x & -x);
                    }
                    cout << acc - v[i-1] << endl;
                    break;
                }
        }
    }

    return 0;
}

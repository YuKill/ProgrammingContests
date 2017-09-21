#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

ull gcd(ull a, ull b) {
    if (a < b) return gcd(b, a);

    while (b != 0) {
        ull b_ = b;
        b = a % b;
        a = b_;
    }

    return a;
}

ull lmc(ull a, ull b) {
    return (a * b) / gcd(a, b);
}

int main() {
    ull n, l;
    cin >> n >> l;

    ull c[n];
    ull lmc_all = 1;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        lmc_all = lmc(lmc_all, c[i]);
    }

    ull ans = l / lmc_all, ans_cpy = ans;

    vector<ull> factors;

    if (!(ans_cpy & 1)) factors.push_back(2);
    while (!(ans_cpy & 1)) {
        ans_cpy >>= 1;
    }

    for (int i = 3; i*i < ans_cpy; i += 2) {
        if (ans_cpy % i == 0) factors.push_back(i);
        while (ans_cpy % i == 0) {
            ans_cpy /= i;
        }
    }

    if (ans_cpy != 1) factors.push_back(ans_cpy);

    for (ull i : factors) {
        while (lmc_all % i == 0) {
            lmc_all /= i;
            ans *= i;
        }
    }

    cout << ans << endl;
    return 0;
}

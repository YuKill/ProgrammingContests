#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

ull combination(ull n, ull k) {
    ull r = 1;
    for (int i = 1; i <= k; ++i) {
        r *= (n - k + i);
        r /= i;
    }
    return r;
}

int main() {
    ull n;
    cin >> n;

    ull primes = 0;

    if ((n & 1) == 0) ++primes;
    while ((n & 1) == 0) n >>= 1;

    for (int i = 3; i*i < n; i += 2) {
        if (n % i == 0) ++primes;
        while (n % i == 0) n /= i;
    }

    if (n > 1) ++primes;

    ull desp = 0;
    for (int i = 2; i <= primes; ++i) {
        desp += combination(primes, i);
    }

    cout << desp << endl;
    return 0;
}

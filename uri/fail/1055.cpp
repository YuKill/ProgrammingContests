#include <iostream>
#include <deque>
#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long ll;

int getsum(deque<int>& d) {
    int sum = 0;
    for (int i = 1; i < d.size(); ++i)
        sum += abs(d[i] - d[i-1]);
    return sum;
}

void printd(deque<int>& d) {
    cout << "[";
    for (int i = 0; i < d.size(); ++i)
        cout << " " << d[i];
    cout << " ]" << endl;
}

int main() {
    int t;
    cin >> t;

    for (int k = 0; k < t; ++k) {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        std::sort(v.begin(), v.end());

        deque<int> d;
        int l = 1, r = n-1;

        d.push_front(v[0]);
        while (true) {
            if (l > r) break;
            d.push_front(v[r--]);
            // printd(d);

            if (l > r) break;
            d.push_back(v[r--]);
            // printd(d);

            if (l > r) break;
            d.push_front(v[l++]);
            // printd(d);

            if (l > r) break;
            d.push_back(v[l++]);
            // printd(d);
        }

        int sum = getsum(d);

        if (n == 3) {
            deque<int> d;
            int l = 0, r = n-2;

            d.push_front(v[n-1]);
            while (true) {
                if (l > r) break;
                d.push_front(v[l++]);
                // printd(d);

                if (l > r) break;
                d.push_back(v[l++]);
                // printd(d);

                if (l > r) break;
                d.push_front(v[r--]);
                // printd(d);

                if (l > r) break;
                d.push_back(v[r--]);
                // printd(d);
            }

            int sump = getsum(d);
            if (sum > sump) sum = sump;
        }

        cout << "Case " << k+1 << ": " << sum << endl;
    }
}

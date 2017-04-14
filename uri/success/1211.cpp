#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    for (int n; cin >> n;) {
        vector<string> tels(n, "");

        for (int i = 0; i < n; ++i)
            cin >> tels[i];

        sort(tels.begin(), tels.end());

        int len = tels[0].length();
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            string &last = tels[i-1], &cur = tels[i];

            int k = 0;
            for (;k < len && cur[k] == last[k]; ++k);
            cnt += k;
        }

        cout << cnt << endl;
    }
    return 0;
}

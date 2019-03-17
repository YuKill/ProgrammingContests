#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<bool> turnedOn(m, false);
    vector<vector<int>> switches(n, vector<int>());

    int l;
    cin >> l;
    for (int i = 0; i < l; ++i) {
        int lamp;
        cin >> lamp;
        turnedOn[--lamp] = true;
    }

    for (int i = 0; i < n; ++i) {
        int lamps;
        cin >> lamps;

        for (int j = 0; j < lamps; ++j) {
            int lamp;
            cin >> lamp;
            switches[i].push_back(--lamp);
        }
    }

    bool succeeded = false;
    int count = 0;

    for (int i = 0; i < 3 && !succeeded; ++i) {
        for (int swt = 0; swt < n && !succeeded; ++swt) {
            for (auto l : switches[swt]) {
                turnedOn[l] = !turnedOn[l];
            }

            succeeded = true;
            for (int lamp = 0; lamp < m; ++lamp) {
                if (turnedOn[lamp]) {
                    succeeded = false;
                    break;
                }
            }

            ++count;
        }
    }

    if (succeeded) {
        cout << count << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int losses = 0;
    for (int x, i = 0; i < n; ++i) {
        cin >> x;
        if (x == 1) losses++;
    }

    cout << n - losses << endl;
    return 0;
}

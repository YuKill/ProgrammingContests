#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    unsigned r = 0;
    for (auto c : s) {
        r = (r + (c - '0')) % 3;
    }

    cout << r << endl;
    return 0;
}

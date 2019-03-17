#include <iostream>
#include <string>

using namespace std;

int main() {
    string msg, crib;
    cin >> msg >> crib;

    int start = 0;
    int count = 0;

    int lim = msg.length() - crib.length() + 1;
    for (int start = 0; start < lim; ++start) {
        bool found = false;
        for (int i = 0; i < crib.length(); ++i) {
            if (msg[start + i] == crib[i]) {
                found = true;
                break;
            }
        }

        if (found) ++count;
    }

    cout << lim - count << endl;
    return 0;
}

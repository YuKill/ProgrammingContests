#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        bool ones = false;

        for (int i = 0, e = line.length(); i < e;) {
            int r = i + 1;
            while (r < e && r - i < 9 && line[i] == line[r]) ++r;

            int rep = r - i;
            if (rep >= 2) {
                if (ones) cout << "1";
                ones = false;

                cout << rep << line[i];
            } else {
                if (!ones) {
                    ones = true;
                    cout << "1";
                }

                if (line[i] == '1')
                    cout << line[i];
                cout << line[i];
            }

            i += rep;
        }

        if (ones) cout << "1";

        cout << endl;
    }
    return 0;
}

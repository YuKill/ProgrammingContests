
#include <iostream>
#include <string>

using namespace std;

inline char getRepr(char c) {
    switch (c) {
        case '0': return '#';
        case ' ': return '$';
        default: return c;
    }
}

int main() {

    int t;
    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; ++i) {
        string s;
        getline(cin, s);

        for (int k = 0, len = s.length(); k < len;) {
            char c = s[k];
            int _k = k + 1;
            if (c == '0' || c == ' ') {
                while (s[_k] == c) ++_k;

                int rep = _k - k;
                if (rep <= 2)
                    for (int j = 0; j < rep; ++j)
                        cout << c;
                else {
                    int blk = rep / 255;
                    int rest = rep % 255;

                    for (int j = 0; j < blk; ++j)
                        cout << getRepr(c) << (unsigned char) 255;
                    cout << getRepr(c) << (unsigned char) rest;
                }
            } else cout << c;

            k = _k;
        }

        cout << endl;
    }

    return 0;
}

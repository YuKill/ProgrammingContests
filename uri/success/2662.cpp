#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<bool> v(12, false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        v[(p-1) % 12] = true;
    }

    bool desaf = true;

    vector<string> name { "do","do#","re","re#","mi","fa","fa#","sol","sol#","la","la#","si" };
    vector<int> dist { 2, 2, 4, 4, 5, 7, 7, 9, 9, 11, 11, 12 };
    for (int i = 0; i < 12; ++i) {
        bool fail = false;

        for (int j = (i+1) % 12, k = 0; j != i; j = (j+1) % 12, ++k) {
            int pos = (i + dist[k]) % 12;

            if (v[j] && j != pos) {
                fail = true;
                break;
            }
        }

        if (!fail) {
            cout << name[i] << endl;
            desaf = false;
            break;
        }
    }

    if (desaf) {
        cout << "desafinado" << endl;
    }
    return 0;
}

#include <string>
#include <iostream>

using namespace std;

int main() {
  string s;
  while (getline(cin, s)) {
    char space = ' ', last = toupper(s[0]);
    int pos = -1, cnt = 0;
    bool found = false;

    while ((pos = s.find(space, pos+1)) != string::npos) {
      s[pos+1] = toupper(s[pos+1]);
      if (last == s[pos+1] && !found) {
        found = true;
        cnt++;
      } else if (last != s[pos+1]) {
        found = false;
        last = s[pos+1];
      }
    }

    cout << cnt << endl;
  }
}

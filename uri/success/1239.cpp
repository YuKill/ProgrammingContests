#include <string>
#include <iostream>

using namespace std;

int main() {
  string s;
  while (getline(cin, s)) {
    int len = s.length(), und = 0, star = 0, start = 0;

    for (int i = 0; i < len; i++) {
      if (s[i] != '*' && s[i] != '_') continue;
      string sub;
      if (i-start > 0) {
        sub = s.substr(start, i-start);
        cout << sub;
      }
      if (s[i] == '*') {
        star++;
        if (star%2) cout << "<b>";
        else cout << "</b>";
      } else if (s[i] == '_') {
        und++;
        if (und%2) cout << "<i>";
        else cout << "</i>";
      }
      start = i+1;
    }
    if (len-start >= 1) {
      string sub = s.substr(start, len-start);
      cout << sub;
    }
    cout << endl;
  }
}

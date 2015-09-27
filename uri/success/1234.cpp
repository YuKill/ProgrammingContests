#include <string>
#include <iostream>
#include <cctype>

using namespace std;

int main() {
  string s;
  while (getline(cin, s)) {
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
      if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
        if (!(cnt % 2))
          s[i] = toupper(s[i]);
        else
          s[i] = tolower(s[i]);
        cnt++;
      }
    }
    cout << s << endl;
  }
}

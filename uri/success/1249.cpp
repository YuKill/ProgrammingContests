#include <string>
#include <iostream>

using namespace std;

int main() {
  string s;
  while (getline(cin, s)) {
    for (int i = 0; i < s.length(); i++) {
      if (s[i] < 'A' || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z') continue;
      bool is_lower = (s[i] <= 'z' && s[i] >= 'a');
      if (is_lower) s[i] -= ('a' - 'A');
      s[i] = (((s[i]-'A') + 13) % 26) + 'A';
      if (is_lower) s[i] += ('a' - 'A');
    }
    cout << s << endl;
  }
}

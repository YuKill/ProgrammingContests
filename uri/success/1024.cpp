#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  cin.ignore(100, '\n');
  
  for (int t = 0; t < tests; t++) {
    string s;
    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {
      if (('a' <= s[i] && 'z' >= s[i]) || ('A' <= s[i] && 'Z' >= s[i]))
        s[i] = s[i]+3;
    }
    reverse(s.begin(), s.end());

    for (int i = (int)floor((double)s.length()/2.0); i < s.length(); i++) {
      s[i] = s[i] -1;
    }

    cout << s << endl;
  }
}

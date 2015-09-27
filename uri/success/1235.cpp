#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  cin.ignore(100, '\n');

  for (int t = 0; t < tests; t++) {
    string s, front, back;
    getline(cin, s);
    
    front = s.substr(0, s.length()/2);
    back = s.substr(s.length()/2, s.length()/2);

    reverse(front.begin(), front.end());
    reverse(back.begin(), back.end());

    cout << front << back << endl;
  }
}

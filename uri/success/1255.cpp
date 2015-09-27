#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

int compare(const void *a, const void *b) {
  return (*(char*)a - *(char*)b);
}

int main() {
  int tests;
  cin >> tests;
  cin.ignore(100, '\n');

  for (int t = 0; t < tests; t++) {
    string s, win;
    getline(cin, s);

    int freq[26], max = 0;
    for (int i = 0; i < 26; i++) freq[i] = 0;

    for (int i = 0; i < s.length(); i++) {
      if (isupper(s[i]) || islower(s[i])) {
        int n = toupper(s[i])-'A';
        freq[n]++;
        if (freq[n] > max) max = freq[n];
      }
    }

    int cnt = 0;
    for (int i = 0; i < 26; i++) 
      if (freq[i] == max) win += (char)(i+'a');

    qsort((void*)win.c_str(), win.length(), 1, compare);
    cout << win << endl;
  }
}

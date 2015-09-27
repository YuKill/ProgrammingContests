#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

int compare(const void *a, const void *b) {
  return (*(char*)a - *(char*)b);
}

int main() {
  int tests;
  cin >> tests;
  cin.ignore(100, '\n');

  for (int t = 0; t < tests; t++) {
    string diet, brk, lunch;
    getline(cin, diet);
    getline(cin, brk);
    getline(cin, lunch);

    bool cheater = false;
    for (int i = 0; i < brk.length() && brk[i] != '\n'; i++) {
      int pos = diet.find(brk[i]);
      if (pos == string::npos) {
        cheater = true;
        break;
      }
      diet[pos] = '*';
    }

    if (cheater) {
      cout << "CHEATER" << endl;
      continue;
    }

    for (int i = 0; i < lunch.length() && lunch[i] != '\n'; i++) {
      int pos = diet.find(lunch[i]);
      if (pos == string::npos) {
        cheater = true;
        break;
      }
      diet[pos] = '*';
    }

    if (cheater) {
      cout << "CHEATER" << endl;
      continue;
    }

    qsort((void*)diet.c_str(), diet.length(), 1, compare);
    for (int i = 0; i < diet.length(); i++)
      if (diet[i] != '*' && diet[i] != '\n') cout << diet[i];
    cout << endl;
  }
}

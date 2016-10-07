#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int T;
  scanf("%d", &T);

  for (int I = 0; I < T; ++I) {
    int M, N;
    scanf("%d %d\n", &M, &N);

    unordered_map<string, string> Dictionary;
    for (int J = 0; J < M; ++J) {
      string Key, Value;
      getline(cin, Key);
      getline(cin, Value);
      Dictionary[Key] = Value;
    }

    for (int J = 0; J < N; ++J) {
      string Translated, Line;
      getline(cin, Line);
      if (Line.empty()) {
        cout << endl;
        continue;
      }

      size_t Last = 0;
      size_t Found = 0;
      do {
        Found = Line.find(" ", Last);
        string Keyword = Line.substr(Last, Found - Last);
        if (Dictionary.count(Keyword) > 0)
          Translated += " " + Dictionary[Keyword];
        else
          Translated += " " + Keyword;
        Last = Found+1;
      } while (Found != string::npos);

      cout << Translated.substr(1) << endl;
    }
    cout << endl;
  }
}

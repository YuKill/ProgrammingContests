#include <iostream>
#include <string>
#include <map>

#include <ctype.h>

using namespace std;

int main() {
  int M = 0;
  while (cin >> M && M) {
    cin.ignore();

    string Line;
    getline(cin, Line);

    map<char, int> Idx;

    int End = 0;
    int Begin = 0;
    int Max = 0;
    int Length = Line.length();
    while (End < Length) {
      while (Idx.size() <= M && End < Length) {
        if (Idx.count(Line[End]) > 0)
          ++Idx[Line[End++]];
        else if (Idx.size() < M)
          Idx[Line[End++]] = 1;
        else
          break;
      }

      Max = (Max < End - Begin) ? End - Begin : Max;

      --Idx[Line[Begin]];
      if (!Idx[Line[Begin]]) Idx.erase(Line[Begin]);
      ++Begin; 
    }

    cout << Max << endl;
  }

  return 0;
}

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<char, int> OpW = {
  {'+', 0},
  {'-', 0},
  {'*', 1},
  {'/', 1},
  {'^', 2}
};

int resolve(string Formula, int Start) {
  string PosFix = "";
  stack<char> Op;
  int I;
  for (I = Start; I < Formula.length(); ++I) {
    char Char = Formula[I];
    if (Char == '(')   
      I = resolve(Formula, I+1);
    else if (Char == ')')
      break;
    else if ((Char >= 48 && Char <= 57) || (Char >= 65 && Char <= 90) || (Char >= 97 && Char <= 122))
      cout << Char; 
    else {
      if (Op.empty() || OpW[Op.top()] < OpW[Char])
        Op.push(Char); 
      else if (OpW[Op.top()] >= OpW[Char]) {
        while (!Op.empty() && OpW[Op.top()] >= OpW[Char]) {
          cout << Op.top();
          Op.pop();
        }
        Op.push(Char);
      }
    }
  }
  while (!Op.empty()) {
    cout << Op.top();
    Op.pop();
  }
  return I;
}

int main() {
  int T;
  scanf("%d\n", &T);

  for (int I = 0; I < T; ++I) {
    string Formula;
    getline(cin, Formula);
    resolve(Formula, 0);
    cout << endl;
  }
}

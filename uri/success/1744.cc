#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
  long long Cost, AdjCost;
  cin >> Cost >> AdjCost;

  string S;
  cin >> S;

  vector<int> BlackAuxPos, BlackPos;
  vector<int> WhitePos;
  for (int I = 0, E = S.length(); I < E; ++I)
    if (S[I] == 'B')
      BlackAuxPos.push_back(I);

  for (int I = 0, E = BlackAuxPos.size(); I < E; ++I)
    if (BlackAuxPos[I] > E-1)
      BlackPos.push_back(BlackAuxPos[I]);

  for (int I = 0, E = BlackAuxPos.size(); I < E; ++I)
    if (S[I] == 'W')
      WhitePos.push_back(I);

  unsigned long long TotalCost = 0;
  int Size = BlackPos.size();
  int Wi = WhitePos.size() - 1;
  for (int I = 0; I < Size; ++I) {
    long long AdjLocalCost = (BlackPos[I] - WhitePos[Wi]) * (Cost - AdjCost);
    long long LocalCost = min(Cost, AdjLocalCost);
    if (LocalCost != Cost) --Wi;
    TotalCost += LocalCost;
  }

  cout << TotalCost << endl;

  return 0;
  
}

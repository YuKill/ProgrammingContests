#include <stdio.h>
#include <iostream>
#include <string>
#include <set>

using namespace std;

struct Reindeer {
  string Name;
  int Weight;
  int Age;
  double Height;
};

struct ReindeerCompare {
  bool operator()(const Reindeer &Lhs, const Reindeer &Rhs) {
    if (Lhs.Weight != Rhs.Weight)
      return Lhs.Weight > Rhs.Weight;
    if (Lhs.Age != Rhs.Age)
      return Lhs.Age < Rhs.Age;
    if (((int)(Lhs.Height * 100)) !=  ((int)(Rhs.Height * 100)))
      return Lhs.Height < Rhs.Height;
    if (Lhs.Name != Rhs.Name)
      return Lhs.Name < Rhs.Name;
    return false;
  }
};

int main() {
  int T;
  scanf("%d", &T);

  for (int I = 1; I <= T; ++I) {
    int N, M;
    scanf("%d %d", &N, &M);

    set<Reindeer, ReindeerCompare> Reindeers;
    for (int J = 0; J < N; ++J) {
      char Name[128];
      Reindeer R;
      scanf("%s %d %d %lf", Name, &R.Weight, &R.Age, &R.Height);
      R.Name = Name;
      Reindeers.insert(R);
    }


    cout << "CENARIO {" << T << "}" << endl;
    int Count = 1;
    for (auto It = Reindeers.begin(), E = Reindeers.end(); It != E; ++It) {
      if (Count > M) break; 
      cout << Count++ << " - " << (*It).Name << endl;
    }
  }
}

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;

bool secondOrder(pair<ll, ll> I, pair<ll, ll> J) {
  return I.second < J.second;
}

int main() {
  int MinMax = 3600;
  int N;
  cin >> N;
  
  vector<pair<ll, ll> > Time(N, make_pair(0, 0));
  for (int I = 0; I < N; ++I)
    cin >> Time[I].first >> Time[I].second;

  sort(Time.begin(), Time.end(), secondOrder);

  vector<ll> Sch(MinMax+1, 0);
  int J = 0;
  for (int I = 1; I <= MinMax;) {
    if (Time[J].second == I) {
      pair<ll, ll> P = Time[J];
      Sch[I] = max(Sch[I], P.second - P.first + Sch[P.first]);
      Sch[I] = max(Sch[I], Sch[I-1]);
      ++J; 
    } else {
      if (!Sch[I]) Sch[I] = Sch[I-1]; 
      ++I;
    }
  }

  cout << Sch[MinMax] << endl;

  return 0;
}

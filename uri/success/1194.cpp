#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

void merge(int &Prex, string Pre, string In) {
  if (In.length() <= 1) {
    if (In.length() == 1) cout << In;
    else --Prex;
    return;
  }

  int I = 0;
  while (Pre[Prex] != In[I]) ++I;

  string LIn = In.substr(0, I);
  string RIn = In.substr(I+1, string::npos);

  ++Prex;
  merge(Prex, Pre, LIn);

  ++Prex;
  merge(Prex, Pre, RIn);
  cout << In[I];
}

int main() {
  int T;
  cin >> T;

  for (int Ti = 0; Ti < T; ++Ti) {
    int N;
    cin >> N;

    string Pre, In;
    cin >> Pre >> In;

    int Prex = 0;
    merge(Prex, Pre, In);
    cout << endl;
  }

  return 0;
}

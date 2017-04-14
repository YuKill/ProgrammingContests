#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;

int companyToInt(string comp) {
  int ans = 0;
  for (int i = 0, e = comp.size(); i < e; ++i)
    ans |= 1 << (comp[i] - 'a');
  return ans;
}

string intToCompany(int x) {
  string ans = "";
  if (!x) return "-";
  for (int i = 0; i < 26; ++i)
    ans += ((x >> i) & 1) * (i + 'a');
  return ans;
};

int main() {
  int n;
  vector< vector<int> > matAdj;

  while (cin >> n && n) {
    int u, v;
    
    matAdj.assign(n, vector<int>(n, 0));
    while (cin >> u >> v && (u || v)) {
      --u; --v;
      string company;

      cin >> company;
      matAdj[u][v] = companyToInt(company);
    }

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          matAdj[j][k] = (matAdj[j][i] & matAdj[i][k]) | matAdj[j][k];
        }
      }

    while (cin >> u >> v && (u || v)) {
      --u; --v;
      string comp = intToCompany(matAdj[u][v]);
      cout << comp << endl;
    }

    cout << endl;
  }

  return 0;
}

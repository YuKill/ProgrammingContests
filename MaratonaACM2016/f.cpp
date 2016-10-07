#include <iostream>
#include <vector>

using namespace std;

void printV(vector<int> V) {
  cout << "[ ";
  for (int i = 0; i < V.size(); ++i)
    cout << V[i] << " ";
  cout << "]" << endl;
}

int main() {
  int nd, ne, idx;
  cin >> ne;

  vector<int> lefty(ne+1, 0);
  idx = 1;
  lefty[0] = 1;
  for (int i = 0; i < ne; ++i) {
    int j, l, k;
    cin >> j >> l >> k;
    if (!lefty[j]) lefty[j] = 1;
    if (l) lefty[l] = 1;
    if (k) {
      if (j == idx) {
        ++lefty[0];
        idx = k;
      }
      lefty[k] = lefty[j] + 1;
    }
  }

  cin >> nd;
  vector<int> righty(nd+1, 0);
  idx = 1;
  righty[0] = 1;
  for (int i = 0; i < nd; ++i) {
    int p, q, r;
    cin >> p >> q >> r;
    if (!righty[p]) righty[p] = 1;
    if (q) { 
      if (p == idx) {
        ++righty[0];
        idx = q;
      }
      righty[q] = righty[p] + 1;
    }
    if (r) righty[r] = 1;
  }

  int maxL = 0, maxR = 0;

  for (int i = 0; i <= ne; ++i)
    if (i > 0 && lefty[i] > maxL)
      maxL = lefty[i];

  for (int i = 0; i <= nd; ++i)
    if (i > 0 && righty[i] > maxR)
      maxR = righty[i];

  int sum = nd + ne;
  cout << sum - max(min(maxL, righty[0]), min(maxR, lefty[0])) << endl;

  return 0;
}

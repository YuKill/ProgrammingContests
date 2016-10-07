#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <climits>

#define ll unsigned long long

using namespace std;

struct Node {
  ll min, max;
};

int decHex(char c) {
  if (c >= '0' && c <= '9')
    return c - '0';
  return c - 'a' + 10;
}

ll toDec(string s, int m) {
  ll dec = 0;

  int exp = 0;
  for (int i = s.length() - 1; i >= 0; --i) {
    int dig = decHex(s[i]);
    if (!((m >> dig) & 1))
      dec += (dig * pow(16, exp++));
  }

  return dec;
}

int humDistance(ll n, int end) {
  int is = 0;
  for (int i = 0; i < end; ++i)
    if ((n >> i) & 1) ++is;
  return is;
}

int main() {
  int n;
  cin >> n;

  ll mod = toDec("3b9aca07", 0);

  ll rate[] = {
    1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 
    3628800, 39916800, 479001600, 6227020800, 87178291200, 
    1307674368000, 20922789888000
  };

  /*
  for (int i = 0; i < 17; ++i)
    rate[i] = rate[i] % mod;
    */

  vector<string> seq(n, "");
  for (int i = 0; i < n; ++i)
    cin >> seq[i];

  ll totPerm = 0;

  int limit = 1 << 16;
  vector<ll> totVec(17, 0);
  vector<Node> totSum(limit, { LLONG_MAX, 0 });
  vector<ll> sum(limit, 0);

  totSum[0].min = 0;
  for (int i = 1; i < limit; ++i) {
    for (int j = 0, e = seq.size(); j < e; ++j) {
      cout << seq[j] << "(" << i << "): " << toDec(seq[j], i) << endl;
      sum[i] += toDec(seq[j], i);
    }

    int hDist = humDistance(i, 16);
    // totPerm = (totPerm + (((sum[i] % mod) * rate[hDist]) % mod)) % mod;
    cout << "dist:" << hDist << endl;
    totVec[hDist] = (totVec[hDist] + ((sum[i] % mod) * (rate[hDist] % mod)) % mod) % mod;

    for (int j = 0; j < 16; ++j) {
      if ((i >> j) & 1) {
        int idx = i - (1 << j);
        cout << "totSum[" << i << "] = totSum[" << idx << "](min:" << totSum[idx].min << ", max:" << totSum[idx].max << ") + " << sum[i] << endl;
        totSum[i].min = min(totSum[i].min, totSum[idx].min + sum[i]);
        totSum[i].max = max(totSum[i].max, totSum[idx].max + sum[i]);
      }
    }
  }

  cout << "[ ";
  for (int i = 0; i < totVec.size(); ++i)
    cout << totVec[i] << " ";
  cout << "]" << endl;

  for (int i = 0; i < totVec.size(); ++i)
    totPerm = (totPerm + totVec[i]) % mod;

  int last = limit - 1;
  cout << last << endl;
  cout << "min: " << totSum[last].min << " max:" << totSum[last].max << " tot:" << totPerm << endl;
  cout << "min: " << hex << totSum[last].min << " max:" << hex << totSum[last].max << " tot:" << hex << totPerm << endl;

  return 0;
}

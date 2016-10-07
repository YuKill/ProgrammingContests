#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

#define ll long long

using namespace std;

void getPrimes(vector<int> &primes) {
  int size = sqrt(1000000000);
  vector<bool> processed(size+1, false);
  for (int i = 2; i <= size; ++i) {
    if (!processed[i]) {
      primes.push_back(i);
      for (int j = i; j <= size; j += i)
        processed[j] = true;
    }
  }
}

int main () {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (c % a != 0) {
    cout << "-1" << endl;
    return 0;
  }

  vector<int> primes, factors;
  getPrimes(primes);

  int pfI = 1;
  int pf = primes[0];
  while (pf * pf <= c) {
    if (pf == a) c /= pf;
    while (c % pf == 0) {
      c /= pf;
      factors.push_back(pf);
    }
    pf = primes[pfI++];
  }
  if (c > 1 && c != a) factors.push_back(c);

  int limit = 1 << (factors.size());
  ll minN = LLONG_MAX;
  for (int i = 0; i <= limit; ++i) {
    ll n = a;
    for (int j = 0, e = factors.size(); j < e; ++j)
      if ((i >> j) & 1) n *= factors[j];

    if (n % b != 0 && d % n != 0) {
      if (minN > n) minN = n;
    }
  }

  if (minN == LLONG_MAX)
    cout << "-1" << endl;
  else
    cout << minN << endl;

  return 0;
}

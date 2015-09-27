#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <vector>

#define ll long long

using namespace std;

void factorization(ll n, vector<ll> &f) {
  for (ll i = 2; i*i <= n; i += 2) {
    if (n % i == 0) f.push_back(i);
    while (n % i == 0) n /= i ;
    if (i == 2) i--;
  }

  if (n > 1) f.push_back(n);
}

void prime_table(ll n, vector<ll> &p) {
  ll pr[n];
  for (ll i = 0; i < n; i++) pr[i] = 1;

  pr[0] = 0;
  pr[1] = 0;
  for (ll i = 2; i < n; i++) 
    if (pr[i]) {
      p.push_back(i);
      for(ll j = i+i; j <= n; j += i) pr[j] = 0;
    }
}

ll pow_mod_T(ll a, ll b, ll T) {
  ll r = 1;
  while (b) {
    if (b % 2) r = (r * (a % T)) % T;
    a = ((a % T) * (a % T)) % T;
    b /= 2;
  }
  return r;
}

bool trial_division(ll n) {
  if (n % 2 == 0) return false;
  for (ll i = 3; i*i <= n; i += 2) { 
    if (n % i == 0) return false;
  }
  return true;
}

bool is_prime(ll n, int k) {
  if (n == 2 || n == 3) return true;
  if (k > n) k = n;

  srand(time(NULL));
  ll d = n-1, s = 0, a;

  while (d % 2 == 0) {
    d /= 2;
    s++;
  }

  for (int i = 0; i < k; i++) {
    bool flag = false;
    a = (rand() % (n-3) + 2);
    a = pow_mod_T(a, d, n);
    if (a == 1 || a == n-1) continue;
    for (int j = 0; j < s-1; j++) {
      a = (a * a) % n;
      if (a == 1) return false;
      else if (a == n-1) {
        flag = true;
        break;
      }
    }
    if (flag) continue;
    return false;
  }
  return true;
}


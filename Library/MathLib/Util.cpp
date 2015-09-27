#include <stdio.h>
#include <math.h>

#define ll long long
#define ull unsigned long long

ll gcd(ll a, ll b) {
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  return (a * b)/gcd(a, b);
}

ll combination(ll n, ll k) {
  if (k == 0) {
    return 1;
  }
  ll r;

  r = combination(n-1, k-1);

  r *= n;
  r /= k;

  return r;
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

ll fib(ll n) {
  double SQ5 = sqrt(5);
  double GR = (1 + SQ5) / 2.0;
  return (ll) (floor(pow(GR, n) / SQ5) + 0.5);
}

ll fib_matrix(ll n) {
  ll r[2][2], a[2][2], b = n-1, aux[2][2];

  r[0][0] = 1;
  r[0][1] = 0;
  r[1][0] = 0;
  r[1][1] = 1;

  a[0][0] = 1;
  a[0][1] = 1;
  a[1][0] = 1;
  a[1][1] = 0;

  while (b) {
    if (b % 2) {
      aux[0][0] = (r[0][0] * a[0][0]) + (r[0][1] * a[1][0]);
      aux[0][1] = (r[0][0] * a[0][1]) + (r[0][1] * a[1][1]);
      aux[1][0] = (r[1][0] * a[0][0]) + (r[1][1] * a[1][0]);
      aux[1][1] = (r[1][0] * a[0][1]) + (r[1][1] * a[1][1]);   

      r[0][0] = aux[0][0];
      r[0][1] = aux[0][1];
      r[1][0] = aux[1][0];
      r[1][1] = aux[1][1];
    }
    aux[0][0] = (a[0][0] * a[0][0]) + (a[0][1] * a[1][0]);
    aux[0][1] = (a[0][0] * a[0][1]) + (a[0][1] * a[1][1]);
    aux[1][0] = (a[1][0] * a[0][0]) + (a[1][1] * a[1][0]);
    aux[1][1] = (a[1][0] * a[0][1]) + (a[1][1] * a[1][1]);   

    a[0][0] = aux[0][0];
    a[0][1] = aux[0][1];
    a[1][0] = aux[1][0];
    a[1][1] = aux[1][1];
    b /= 2;
  }
  return r[0][0];
}

int hamming_weight(ull n) {
  ull m1 = 0x5555555555555555,
      m2 = 0x3333333333333333,
      m4 = 0x0f0f0f0f0f0f0f0f,
      m8 = 0x00ff00ff00ff00ff,
      m16 = 0x0000ffff0000ffff,
      m32 = 0x00000000ffffffff;
  ull r;
  r = (n & m1) + ((n >> 1) & m1);
  r = (r & m2) + ((r >> 2) & m2);
  r = (r & m4) + ((r >> 4) & m4);
  r = (r & m8) + ((r >> 8) & m8);
  r = (r & m16) + ((r >> 16) & m16);
  r = (r & m32) + ((r >> 32) & m16);

  return (int) r;
}

ll euler_tot(ll n) {
  double result = n;
  for (ll i = 2; i*i <= n; i += 2) {
    if (n % i == 0) {
      result *= (1.0 - (1.0 / i)); 
    }
    while (n % i == 0) n /= i;
    if (i == 2) i--;
  }
  if (n > 1) result *= (1.0 - (1.0 / n)); 
  return (ll) result;
}

// inverse of a mod b
ll mod_inverse_tot(ll a, ll b) {
  return pow_mod_T(a, euler_tot(b)-1, b);  
}

ll mod_inverse(ll a, ll b) {
  ll old_r = a, r = b;
  ll old_inv = 1, inv = 0;

  while (r != 0) {
    ll q, new_r, new_inv;

    q = old_r / r;

    new_r = old_r - (r * q);
    old_r = r;
    r = new_r;

    new_inv = old_inv - (inv * q);
    old_inv = inv;
    inv = new_inv;
  }

  return (old_inv + b) % b;
}

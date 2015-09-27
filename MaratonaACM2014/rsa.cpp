#include <stdlib.h>
#include <stdio.h>

#define ll long long


ll pow_mod_T(ll   a, ll b, ll T) {
  ll r  =  1;
  while   (b)   {
    if  (b %  2) r  =  (r *  (a %  T))   %  T;
    a =  ((a   %  T) *  (a %  T))   %  T;
    b  /= 2;
  }
  return r;
}

int gcd(ll a, ll b) {
  ll r = 0;
  while (b != 0) {
    ll aux = b;
    b = a % b;
    a = aux;
  }
  return a;
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

ll mod_inverse(ll a, ll b) {
  /*
  ll old_r =  a, r  =  b;
  ll   old_inv  =  1, inv   =  0;
  while  (r != 0) {
    ll q, new_r,   new_inv;

    q   =  old_r /  r;
    new_r   =  old_r -  (r *  q);
    old_r =  r;
    r   =  new_r;
    new_inv =  old_inv  -  (inv  *  q);
    old_inv  =  inv;
    inv =  new_inv;

  }

  return (old_inv + b) % b;
  */
  return pow_mod_T(a, euler_tot(b)-1, b);
}

int main() {
  ll n, e, c, m, d, phi;
  scanf("%lld %lld %lld", &n, &e, &c);

  phi = euler_tot(n);
  d = mod_inverse(e, phi);
  m = pow_mod_T(c, d, n);

  printf("%lld\n", m);
}

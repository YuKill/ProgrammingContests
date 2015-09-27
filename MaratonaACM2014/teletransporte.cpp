#include <stdlib.h>
#include <stdio.h>

#define ll long long
#define MOD 10000

void mult(ll *m1, ll *m2, ll n, ll *r) {
  ll aux[n*n];
  for (int i = 0; i < n*n; i++)
    aux[i] = 0;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      ll soma = 0;
      for (int k = 0; k < n; k++)
        soma += (m1[i*n + k] * m2[k*n + j]);
      aux[i*n + j] = soma;
    }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      r[i*n + j] = aux[i*n + j] % MOD;
}

int main() {
  ll n, l, s, t;
  scanf("%lld %lld %lld %lld", &n, &l, &s, &t);

  s--;
  t--;

  ll m[n*n], r[n*n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int pos = i*n + j;
      if (i == j) r[pos] = 1;
      else r[pos] = 0;
      m[pos] = 0;
    }

  for (int i = 0; i < n; i++) {
    int goTo[4];
    for (int j = 0; j < 4; j++) {
      scanf("%d", &goTo[j]);
      m[i*n + goTo[j]-1]++;
    }
  }

  while (l) {
    if (l % 2) mult(r, m, n, r);
    mult(m, m, n, m);
    l /= 2;
  }

  printf("%lld\n", r[s*n +t]);
}

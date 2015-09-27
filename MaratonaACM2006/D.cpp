#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ll long long

#define min(a,b) ((a) < (b)) ? (a) : (b)

int main() {
  for (ll f, p, e, a; scanf("%lld %lld %lld %lld", &f, &p, &e, &a) != EOF &&
      (f+p+e+a);) {
    ll cost[p][f];
    for (int i = 0; i < p; i++) {
      for (int j = 0; j < f; j++) {
        int joules, time;
        scanf("%d %d", &joules, &time);
        cost[i][j] = joules * time;
      }
    }

    ll m[p][f];
    for (int i = 0; i < f; i++) {
      m[0][i] = cost[0][i];
      if (i != 0)
        m[0][i] += (e * a);
    }

    for (int i = 1; i < p; i++) {
      for (int j = 0; j < f; j++) {
        m[i][j] = m[i-1][j] + cost[i][j]; 
        for (int k = 0; k < f; k++) {
          if (k == j) continue;
          m[i][j] = min(m[i][j], m[i-1][k] + cost[i][j] + (e*a));
        }
      }
    }

    ll total = LLONG_MAX;
    for (int i = 0; i < f; i++) {
      if (m[p-1][i] < total)
        total = m[p-1][i];
    }
    printf("%lld\n", total);
  }
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ull unsigned long long

ull find_x(ull n, ull *p, ull ini, ull x) {
  ull i;
  for (i = ini+1; i < n; i++)
    if (p[i] == x+1) return i;
}

ull gcd(ull a, ull b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

ull lcm(ull a, ull b) {
  return (a * b / gcd(a, b));
}

ull get_cycles(ull n, ull *p) {
  ull i, j, find, t = 1;
  bool ok[n];
  for (i = 0; i < n; i++) ok[i] = false;
  for (i = 0; i < n; i++) {
    if (p[i] == i+1 || ok[i]) continue;
    
    ok[i] = true;
    ull old = p[i] -1, cycle = 1;
    while (old != i) {
      ok[old] = true;
      old = p[old] -1;
      cycle++;
    }
    t = lcm(cycle, t);
  }
  return t;
}

ull crypto(ull n, ull dm, ull *p, char *w, char *r) {
  ull i, j;
  char *aux;
  for (i = 0; i < dm; i++) {
    for (j = 0; j < n; j++)
      r[j] = w[p[j]-1];
    aux = w;
    w = r;
    r = aux;
  }
  strcpy(r, w);
}

int main() {

  ull n, m;
  while (scanf("%llu %llu", &n, &m) != EOF) {
    if (n == 0 && m == 0) break;
  
    ull p[n], i;
    char w[n+1], r[n+1], f[10];

    for (i = 0; i < n; i++)
      scanf("%llu", &p[i]);
    
    sprintf(f, "%%%lluc", n);
    scanf("%*c");
    scanf(f, w);
    w[n] = '\0';
    r[n] = '\0';

    ull cycle = get_cycles(n, p);
    crypto(n, cycle - (m % cycle), p, w, r);
    printf("%s\n", w);
  }
}

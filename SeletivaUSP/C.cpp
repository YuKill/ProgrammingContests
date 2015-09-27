#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define ll long long int
#define PI 3.14159265359

template<class A, class B, class C>
void mult_(A m1, int x, int y, B m2, int z, C r) {
  C aux;
  for (int i = 0; i < x; i++) 
    for (int j = 0; j < z; j++) { 
      aux[i][j] = 0;
      for (int k = 0; k < y; k++) 
        aux[i][j] += m1[i][k] * m2[k][j];
    }

  for (int i = 0; i < x; i++) 
    for (int j = 0; j < z; j++)
      r[i][j] = aux[i][j];
}

template<class A>
void pow_(A m, ll n, A result) {
  A r, aux;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      if (i == j) r[i][j] = 1;
      else r[i][j] = 0;
      aux[i][j] = m[i][j];
    }

  while (n) {
    if (n % 2) mult_<A, A, A>(r, 3, 3, aux, 3, r);
    mult_<A, A, A>(aux, 3, 3, aux, 3, aux);
    n /= 2;
  }

  for (int i = 0; i < 3; i++) 
    for (int j = 0; j < 3; j++)
      result[i][j] = r[i][j];
}

template<class P>
void rotate(P pos, ll a, double l, ll n) {
  double m[3][3];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      m[i][j] = 0;
  m[0][0] = cos(a * PI / 180.0);
  m[0][1] = -sin(a * PI / 180.0);
  m[1][0] = sin(a * PI / 180.0);
  m[1][1] = cos(a * PI / 180.0);
  m[0][2] = l;
  m[2][2] = 1;

  pow_<double [3][3]>(m, n, m);
  mult_<double [3][3], P, P>(m, 3, 3, pos, 1, pos);
}

int main() {
  int test;
  scanf("%d", &test);

  for (int t = 0; t < test; t++) {
    ll a, n;
    double l, pos[3][1];

    pos[0][0] = 0;
    pos[1][0] = 0;
    pos[2][0] = 1;
    scanf("%lld %lf %lld", &a, &l, &n);

    rotate<double [3][1]>(pos, a, l, n);
    printf("%.2lf %.2lf\n", (pos[0][0] < 0.01 && pos[0][0] > -0.01) ? 0.0 : pos[0][0], (pos[1][0] < 0.01 && pos[1][0] > -0.01) ? 0.0 : pos[1][0]);
  }
}

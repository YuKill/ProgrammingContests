#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/*
   double time_(int v) {
   return (double)1.0/v;
   }

   double decide(int s, int c, int v[], int r) {
   double t[s+1][c+1];

   t[0][0] = 0.0;
   for (int i = 1; i <= s; i++) {
   int runs = i;
   if (i > c) runs = c;
   for (int j = 0; j <= runs; j++) {
   if (j == 0) t[i][j] = t[i-1][j] + time_(v[i-1]);
   else if (i == j) t[i][j] = t[i-1][j-1] + time_(v[i-1]+r);
   else t[i][j] = fmin(t[i-1][j]+time_(v[i-1]), t[i-1][j-1]+time_(v[i-1]+r));
   }
   }

   return t[s][c];
   }
   */

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 0; i < t; i++) {
    int s, c, r;
    scanf("%d %d %d", &s, &c, &r);

    int v[s], vf[101];
    for (int j = 0; j <= 100; j++) vf[j] = 0;
    for (int j = 0; j < s; j++) {
      scanf("%d", &v[j]);
      vf[v[j]]++;
    }

    double _time = 0;
    for (int j = 0; j <= 100; j++) {
      while (vf[j]) {
        int vel = j;
        vf[j]--;
        if (c) {
          c--;
          vel = j + r;
        }
        _time += (double)(1.0/vel);
      }
    }
    printf("%.2f\n", _time);
    // printf("%.2f\n", decide(s, c, v, r));
  }
}

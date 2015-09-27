#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
  int n, aah;
  scanf("%d %d", &n, &aah);
  bool possible = true;

  int x[n], y[n], l[n];
  int y_ord[10000];
  
  for (int i = 0; i < 10000; i++) y_ord[i] = -1;

  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &x[i], &y[i], &l[i]);
    y_ord[y[i]] = i;
  }

  int first = -1, second = -1;
  for (int i = 0; i < 10000; i++) {
    int dex = y_ord[i];
    if (dex != -1) {
      if (first == -1) first = dex;
      else second = dex;
    }
    if (first != -1 && second != -1) {
      int *gt = &first, *sml = &second;
      if (x[first] < x[second]) {
        gt = &second;
        sml = &first;
      }
      double diff = fabs((x[*gt] - (l[*gt]/2.0)) - (x[*sml] + l[*sml]/2.0));
      printf("%lf\n", diff);
      double min = fmin(diff, (double)aah);
      if (min != diff) {
        possible = false;
        printf("%d %d %d\n", x[second], y[second], l[second]);
        break;
      }
      first = second;
      second = -1;
    }
  }

  if (possible) printf("YEAH");
  else printf("OUCH");
  printf("\n");
}

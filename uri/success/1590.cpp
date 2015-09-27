#include <stdlib.h>
#include <stdio.h>

void set(bool in[], bool state, int n) {
  for (int i = 0; i < n; i++) in[i] = state;
}

void copy(bool dst[], bool src[], int n) {
  for (int i = 0; i < n; i++) dst[i] = src[i];
}

int get_best_and(int n, int v[], int k) {
  int base = 29, cnt;
  bool in[n], in_old[n];

  set(in, true, n);
  set(in_old, true, n);

  while (base >= 0) {
    cnt = 0;
    for (int i = 0; i < n; i++) {
      if (in[i]) {
        if ((v[i] >> base) & 1) {
          in[i] = true;
          cnt++;
        } else {
          in[i] = false;
        }
      }
    }
    if (cnt < k) {
      copy(in, in_old, n);
    } else if (cnt > k) {
      copy(in_old, in, n);
    } else break;
    base--;
  }

  int bit_and = 0xffffffff;
  for (int i = 0; i < n; i++) {
    if (in[i])
      bit_and = bit_and & v[i];
  }

  return bit_and;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int n, k;
    scanf("%d %d", &n, &k);

    int v[n];
    for (int j = 0; j < n; j++)
      scanf("%d", &v[j]);

    printf("%d\n", get_best_and(n, v, k));
  }
}

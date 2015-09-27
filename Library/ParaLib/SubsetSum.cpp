#include <stdlib.h>
#include <stdio.h>

int *subset_sum(int *a, int n) {
  int M = 0;
  for (int i = 0; i < n; i++) M += a[i];

  int *m = (int*) malloc(sizeof(int) * (M+1)); 
  for (int i = 0; i <= M; i++) m[i] = 0;

  m[0] = 1;
  for (int i = 0; i < n; i++) 
    for (int j = M; j >= a[i]; j--) 
      m[j] |= m[j-a[i]];
  return m;
}

int subset_sum_k(int *a, int n, int k) {
  int M = 0;
  for (int i = 0; i < n; i++) M += a[i];

  int m[M+1]; 
  for (int i = 0; i <= M; i++) m[i] = 0;

  m[0] = 1;
  for (int i = 0; i < n; i++) 
    for (int j = M; j >= a[i]; j--) 
      m[j] |= m[j-a[i]];

  return m[k];
}


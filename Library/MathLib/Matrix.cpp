
#define T int
void mult_(T *m1, T *m2, int n, int m, int o, T *r) {
  T aux[n*o];
  for (int i = 0; i < n*o; i++)
    aux[i] = 0;

  for (int i = 0; i < n; i++) 
    for (int j = 0; j < o; j++) {
      T soma = 0;
      for (int k = 0; k < m; k++)
        soma += m1[i*m + k] * m2[k*o + j];
      aux[i*m + j] = soma;
    }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < o; j++)
      r[i*o + j] = aux[i*o + j];
}

void mult_NxN(T *m1, T *m2, int n, T *r) {
  T aux[n*n];
  for (int i = 0; i < n*n; i++)
    aux[i] = 0;

  for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++) {
      T soma = 0;
      for (int k = 0; k < n; k++)
        soma += m1[i*n + k] * m2[k*n + j];
      aux[i*n + j] = soma;
    }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      r[i*n + j] = aux[i*n + j];
}

void pow_(T *mat, int e, int n, T *r) {
  T aux[n*n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i == j) aux[i*n + j] = 1;
      else aux[i*n + j] = 0;

  while (e) {
    if (e % 2) mult_NxN(aux, mat, n, aux);
    mult_NxN(mat, mat, n, mat);
    e /= 2;
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      r[i*n + j] = aux[i*n + j];
}

int main() {}

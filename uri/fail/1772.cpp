#include <stdlib.h>
#include <stdio.h>

#define ull unsigned long long
/*
ull swap(ull n, ull a, ull b) {
  ull bit_a = (n >> a) & 1, bit_b = (n >> b) & 1;

  if (a != b) {
    if (bit_a)
      n -= (1 << a);
    if (bit_b)
      n -= (1 << b);

    n += (bit_a * (1 << b)) + (bit_b * (1 << a));
  }
  return n;
}
*/

#include <string.h>
#define B 32
void to_bin(ull n, char *bin) {
  int i = 0, k, len;
  while (n > 0) {
    bin[i++] = (char)((n & 1) + 48);
    n >>= 1;
  }
  bin[i] = '\0';
  len = strlen(bin);
  for (k = 0; k < B-len; k++)
    bin[i++] = '0';
  bin[i] = '\0';
}

ull to_dec(char *bin) {
  ull d = 0;
  for (int i = 0; i < B; i++)
    if (bin[i] == '1')
      d += (1 << i);
  return d;
}

ull swap(ull n, ull a, ull b) {
  char bin[B+1], aux;

  to_bin(n, bin);
  aux = bin[a];
  bin[a] = bin[b];
  bin[b] = aux;
  
  return to_dec(bin);
}

int main() {
  ull n, k;
  while (scanf("%llu %llu", &n, &k) != EOF) {
    if (n == 0 && k == 0) break;

    ull maior = n, menor = n;
    for (int i = 0; i < k; i++) {
      ull a, b;
      scanf("%llu %llu", &a, &b);
      n = swap(n, a, b);
      if (maior < n)
        maior = n;
      if (menor > n)
        menor = n;
    }

    printf("%llu %llu %llu\n", n, maior, menor);
  }
}

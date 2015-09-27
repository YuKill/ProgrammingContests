#include <cstdlib>
#include <cstdio>
#include <cstring>

long long dec_to_bin(long long d) {
  long long b = 0, pw = 1;
  while (d > 0) {
    b += (pw * (d & 1));
    d >>= 1;
    pw *= 10;
  }
  return b;
}

long long x_to_dec(char *s) {
  long long d = 0, pw = 1;
  for (long long i = strlen(s)-1; i >= 0; i--) {
    if (s[i] > 57) {
      d += (pw * (s[i] - 87));
    } else {
      d += (pw * (s[i] - '0'));
    }
    pw *= 16;
  }
  return d;
}

void bin_to_x(int b, char *s) {
  char xtab[] = { 
    '0', '1', '2', '3', '4', '5',
    '6', '7', '8', '9', 'a', 'b',
    'c', 'd', 'e', 'f'
  };
  long long cnt = 0;
  while (b > 0) {
    long long ch = b % 10000;
    s[cnt] = xtab[(ch & 1) + (((ch/10) & 1) * 2) + (((ch/100) & 1) * 4) + (((ch/1000) & 1) * 8)];
    cnt++;
    b /= 10000;
  }
  s[cnt] = '\0';
}

int main() {
  int tests;
  scanf("%d", &tests);

  for (int t = 1; t <= tests; t++) {
    char n[32], mod[4];
    long long num;
    scanf("%s %s", n, mod);

    printf("Case %d:\n", t);
    if (!(strcmp(mod, "hex"))) {
      long long d = x_to_dec(n);
      long long b = dec_to_bin(d);
      printf("%lld dec\n", d);
      printf("%lld bin\n", b);
    } else if (!(strcmp(mod, "bin"))) {
      bin_to_x(atoll(n), n);
      long long d = x_to_dec(n);
      printf("%lld dec\n", d);
      printf("%s hex\n", n);
    } else {
      long long b = dec_to_bin(atoll(n));
      bin_to_x(b, n);
      printf("%s hex\n", n);
      printf("%lld bin\n", b);
    }
  }
}

#include <cstdlib>
#include <cstdio>

long long pw(long long a, long long b, long long mod) {
  long long r = 1;
  while (b > 0) {
    if (b % 2) r = (r * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return r;
}

int main() {
  long long n;
  scanf("%lld", &n);

  // 3^n
  long long a = 3, mod = 2147483647;
  long long r = pw(3, n, mod);
  printf("%lld\n", r);
}

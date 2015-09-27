#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 17
#define PMX 100000000000000000
// defines the maximum number
#define NBLK 10

#define ull unsigned long long

class big_int {
  ull blk[NBLK];
  int first;

  void init();

  public:
    big_int(const char*);
    big_int(ull);
    big_int();
    
    void copy(big_int);
    void print();
    void println();

    big_int &operator=(const big_int);
    big_int &operator+=(const big_int);
    big_int &operator*=(const big_int);
    big_int &operator*=(ull);
};

void big_int::init() {
  int i;
  first = 0;
  for (i = 0; i < NBLK; i++) blk[i] = 0;
}

big_int::big_int(const char *s) {
  int len = strlen(s), i, cnt = 0;
  ull p10 = 1;

  init();
  for (i = len -1; i >= 0; i--) {
    blk[cnt / MAX] += p10 * (s[i] - 48);
    if (cnt % MAX == MAX-1)
      p10 = 1;
    else
      p10 *= 10;
    cnt++;
  }
  first = (cnt-1) / MAX;
}

big_int::big_int(ull n) {
  init();
  blk[0] = n;
}

big_int::big_int() {
  init();
}

void big_int::copy(big_int r) {
  int i;
  for (i = 0; i < NBLK; i++) blk[i] = r.blk[i];
  first = r.first;
}

void big_int::print() {
  int i, len, z;
  for (i = first; i >= 0; i--) {
    if (i != first) {
      ull n = blk[i];
      len = 0;
      while (n > 0) {
        n /= 10;
        len++;
      }
      if (len == 0) len = 1;
      for (z = 0; z < MAX-len; z++) printf("0");
    }
    printf("%llu", blk[i]);
  }
}

void big_int::println() {
  print();
  printf("\n");
}

big_int &big_int::operator=(const big_int r) {
  copy(r);
  return *this;
}

big_int &big_int::operator+=(const big_int r) {
  int carry = 0, i;
  const int *f = &first;
  if (first < r.first)
    f = &(r.first);
  for (i = 0; i <= *f; i++) {
    ull sum = blk[i] + r.blk[i] + carry;
    carry = sum / PMX;
    blk[i] = sum % PMX;
  }
  if (carry) {
    blk[i] = carry;
    first = *f + 1;
  }
  return *this;
}

// works only with one digit number
big_int &big_int::operator*=(ull n) {
  int carry = 0, i;
  for (i = 0; i <= first; i++) {
    ull p = (n * blk[i]) + carry;
    carry = p / PMX;
    blk[i] = p % PMX;
  }
  if (carry) {
    blk[i] = carry;
    first++;
  }
  return *this;
}

big_int &big_int::operator*=(const big_int r) {
  big_int prod[];
}

inline big_int operator+(big_int l, const big_int r) {
  l += r;
  return l;
}

int main() {
  big_int a("99999999999999998"), b(1), c;
  c = a + b;
  c.println();
  c *= 7;
  c.println();
}

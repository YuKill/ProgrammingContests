#include <stdlib.h>
#include <stdio.h>

int gcd(int a, int b) {
  return (b == 0) ? a : gcd(b, a%b);
}

typedef struct frac {
  char sign;
  int num, den;
  frac() { sign = '+'; };

  frac &operator=(frac r) {
    sign = r.sign;
    num = r.num;
    den = r.den;
    return *this;
  }

  void print() {
    if (sign != '+') printf("-");
    printf("%d/%d", num, den);
  }

  void reduce() {
    int mdc = gcd(num, den);
    num /= mdc;
    den /= mdc;
  }
} frac;

inline frac operator+(frac l, frac r) {
  l.num = (l.num*r.den)+(r.num*l.den);
  l.den *= r.den;
  return l;
}

inline frac operator-(frac l, frac r) {
  l.num = (l.num*r.den)-(r.num*l.den);
  l.den *= r.den;
  if (l.num < 0) {
    l.num *= -1;
    l.sign = '-';
  }
  return l;
}

inline frac operator/(frac l, frac r) {
  l.num *= r.den;
  l.den *= r.num;
  return l;
}

inline frac operator*(frac l, frac r) {
  l.num *= r.num;
  l.den *= r.den;
  return l;
}

int main() {
  int tests;
  scanf("%d", &tests);

  for (int t = 0; t < tests; t++) {
    frac first, second;
    char op[2];
    scanf("%d / %d", &first.num, &first.den);
    scanf("%s", op);
    scanf("%d / %d", &second.num, &second.den);

    frac r;
    if (op[0] == '+') r = first + second;
    else if (op[0] == '-') r = first - second;
    else if (op[0] == '*') r = first * second;
    else r = first / second;

    r.print();
    printf(" = ");
    r.reduce();
    r.print();
    printf("\n");
  }
}

#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string.h>

using namespace std;

typedef struct frac {
  int num, den;
  frac() { num = 0; den = 0; }
  frac(int n, int d) { num = n; den = d; }
  frac &operator=(frac r) {
    num = r.num;
    den = r.den;
    return *this;
  }
  bool is_one() { return (num == den); }
} frac;

int gcd (int a, int b) {
  if (!b) return a;
  return gcd(b, a%b);
}

inline frac operator+(frac l, frac r) {
  l.num = (l.num*r.den)+(r.num*l.den);
  l.den *= r.den;
  int g = gcd(l.num, l.den);
  l.num /= g;
  l.den /= g;
  return l;
}

int main() {
  map<char, frac> tempo;
  tempo['W'] = frac(1,1);
  tempo['H'] = frac(1,2);
  tempo['Q'] = frac(1,4);
  tempo['E'] = frac(1,8);
  tempo['S'] = frac(1,16);
  tempo['T'] = frac(1,32);
  tempo['X'] = frac(1,64);

  for (char buf[256]; scanf("%s", buf) != EOF && buf[0] != '*';) {
    int len = strlen(buf), cnt = 0;
    bool first = true;
    frac acc;
    for (int i = 0; i < len; i++) {
      if (buf[i] == '/') {
        if (!first && acc.is_one()) cnt++;
        first = true;
      } else if (first) {
        acc = tempo[buf[i]];
        first = false;
      } else acc = acc + tempo[buf[i]];
    }

    printf("%d\n", cnt);
  }
}

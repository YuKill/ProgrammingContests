#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// Calcule quantos fibs existem entre A e B

#define MAX 501
#define UP 0
#define DOWN 1

#define PK 10
#define SPK 15
class big_int {
  public:
    long long n[PK];

  private:
    void init() {
      int i;
      for (i = 0; i < PK; i++)
        n[i] = 0;
    }

    void copy(big_int r) {
      int i;
      for (i = 0; i < PK; i++)
        this->n[i] = r.n[i];
    }

  public:
    big_int() {
      init();
    }

    big_int(char *s) {
      int len = strlen(s), i, t = (int)ceil((double)len/SPK), cur = len, 
          ret = len % SPK, package;
      char *h;
      init();
      for (i = len-1; i >= 0; i--)  {
        package = (t-1);
        if (ret == 0)
          package -= (i/SPK);
        else
          package -= ((i + SPK - (len % SPK)) / SPK);
        n[package] = n[package] + (pow(10, ((len-1-i) % SPK)) * (s[i]-48));
      }

    }
    
    big_int &operator=(big_int r) {
      copy(r);
      return *this;
    }

    big_int &operator=(int r) {
      n[0] = r;
      return *this;
    }

    big_int &operator+=(const big_int &r) {
      int i;
      long long power10 = pow(10, SPK), carry = 0; 
      for (i = 0; i < PK; i++) {
        long long sum;

        sum = r.n[i] + this->n[i] + carry;
        carry = sum / power10;
        sum = sum % power10;

        this->n[i] = sum;
      }

      return *this;
    }
};

inline big_int operator+(big_int l, const big_int &r) {
  l += r;
  return l;
}

inline bool operator<(const big_int &l, const big_int &r) {
  int i;
  for (i = PK-1; i >= 0; i--) {
    bool over_zero = (l.n[i] > 0 || r.n[i] > 0);
    if (over_zero && l.n[i] > r.n[i]) return false;
    else if (over_zero && l.n[i] < r.n[i]) return true;
  }
  return false;
}

inline bool operator>(const big_int &l, const big_int &r) {
  return r < l;
}

inline bool operator==(const big_int &l, const big_int &r) {
  int i;
  for (i = 0; i < PK; i++) {
    if (l.n[i] != r.n[i]) return false;
  }
  return true;
}

inline bool operator<=(const big_int &l, const big_int &r) {
  return (l < r || l == r);
}

void fib(big_int *f) {
  int i;
  f[0] = 0;
  f[1] = 1;
  f[2] = 2;
  for (i = 3; i < MAX; i++)
    f[i] = f[i-1] + f[i-2];
}

int find_closest(big_int n, int m, int start, int end, big_int *f) {
  int i;
  /*
  i = start+floor((end-start)/2.0);

  if (start > end)
    if (m == UP)
      return end;
    else
      return start;

  if (f[i] < n)
    return find_closest(n, m, i+1, end, f);
  else if (f[i] > n)
    return find_closest(n, m, start, i-1, f);
  else
    return i;
    */
  for (i = 1; i < MAX; i++) {
    if (m == DOWN && f[i] > n)
      if (f[i-1] == n) return i-1;
      else return i;
    else if (m == UP && f[i] > n)
      return i-1;
  }
}

int main() {

  char a[1200], b[1200];
  big_int f[MAX];
  fib(f);

  while (scanf("%s %s", a, b) != EOF) {
    bool a_is_zero = (strlen(a) == 1 && a[0] == '0');
    bool b_is_zero = (strlen(b) == 1 && b[0] == '0');
    if (a_is_zero && b_is_zero) break;

    int n1, n2;
    big_int ba(a), bb(b);

    if (a_is_zero) n1 = 1;
    else
      n1 = find_closest(ba, DOWN, 0, MAX, f);
    n2 = find_closest(bb, UP, 0, MAX, f);

    printf("%d\n", n2-n1+1);
  }

  /*
     char c[] = "99999999999999";
     char e[] = "1";
     big_int a(c);
     big_int d(e);
     a.print_b();
     printf("\n");
     d.print_b();
     printf("\n");
     a = a + d;
     a.print_b();
     printf("\n");
     */
}

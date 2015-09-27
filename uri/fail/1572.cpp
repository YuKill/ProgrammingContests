#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 1000
#define LL_MAX 17
#define ll long long

#define EQ 0
#define GRT 1
#define LESS -1

struct big_int {
  int len;
  char s[MAX];
};

typedef struct big_int big_int;

void init(big_int *b, ll n = 0) {
  int i = 0;
  while (n > 0) {
    b->s[i++] = (char)((n % 10) + 48);
    n /= 10;
  }
  b->s[i] = '\0';
  b->len = i;
}

void init(big_int *b, const char *s) {
  int len = strlen(s), i;
  for (i = len-1; i >= 0; i--)
    b->s[len-i-1] = s[i];
  b->len = len;
  b->s[len] = '\0';
}

void copy(big_int *dest, big_int src) {
  int i, len = src.len;
  for (i = 0; i < len; i++)
    dest->s[i] = src.s[i];
  dest->s[i] = '\0';
  dest->len = len;
}

int compare(const char *s1, const char *s2) {
  int l1 = strlen(s1), l2 = strlen(s2);
  if (l1 != l2)
    if (l1 > l2)
      return GRT;
    else
      return LESS;

  int i;
  for (i = l1-1; i >= 0; i--)
    if (s1[i] < s2[i])
      return LESS;
    else if (s1[i] > s2[i])
      return GRT;
  return EQ;
}

void sum(big_int b1, big_int b2, big_int *sum) {
  int len1 = b1.len, len2 = b2.len,
      *gt = &len1, i, carry = 0;
  init(sum);
  if (len2 > len1) gt = &len2;

  for (i = 0; i < *gt; i++) {
    int n1 = 0, n2 = 0, r = 0;
    if (len1 > i) n1 = (b1.s[i] - 48);
    if (len2 > i) n2 = (b2.s[i] - 48);
    r = n1 + n2 + carry;
    carry = r / 10;
    sum->s[i] = (char)((r % 10) + 48);
  }
  if (carry && *gt < MAX) sum->s[i++] = '1'; 

  sum->s[i] = '\0';
  sum->len = i;
}

int sub(big_int b1, big_int b2, big_int *r) {
  // Suposing b1 is bigger than b2
  if (compare(b1.s, b2.s) < 0) return 1;
  int carry = 0, len1 = b1.len, len2 = b2.len, i;
  init(r);

  for (i = 0; i < len1; i++) {
    int n1 = (b1.s[i] - 48) - carry, n2 = 0, 
        dig_sub, use_carry = 0;
    if (i < len2)
      n2 = (b2.s[i] - 48);

    if (n1 < n2) use_carry = 1;
    dig_sub = (use_carry * 10) + n1 - n2;

    if (use_carry) carry = 1;
    else carry = 0;
    r->s[i] = (char)(dig_sub + 48);
  }
  i--;
  while (r->s[i] == '0') i--;
  r->s[++i] = '\0';
  r->len = i;  

  return 0;
}

void mult(big_int b1, big_int b2, big_int *mult) {
  int len1 = b1.len, len2 = b2.len, 
      i, j, carry, shift;
  init(mult);

  big_int m_res[len2]; 
  for (i = 0; i < len2; i++) {
    init(&m_res[i]);
    int n2 = (b2.s[i] - 48);

    for (shift = 0; shift < i; shift++)
      m_res[i].s[shift] = '0';

    carry = 0;
    for (j = shift; j < len1+shift; j++) {
      int n1 = (b1.s[j-shift] - 48),
          r = (n1 * n2) + carry;
      carry = r / 10;
      m_res[i].s[j] = (char)((r % 10) + 48);
    }
    if (carry && len1+shift < MAX) m_res[i].s[j++] = (char)(carry + 48);
    m_res[i].s[j] = '\0';
    m_res[i].len = j;
  }

  if (len2 > 1) sum(m_res[0], m_res[1], mult);
  else if (len2 == 1) copy(mult, m_res[0]);
  for (i = 2; i < len2; i++)
    sum(*mult, m_res[i], mult);
}

void shift_r(big_int *b, int d) {
  int i;
  for (i = b->len -1; i >= 0; i--)
    b->s[i+d] = b->s[i];
  for (i = 0; i < d; i++) b->s[i] = '0';
  b->len += d;
}

void shift_l(big_int *b, int d) {
  int i;
  for (i = d; i < b->len; i++)
    b->s[i-d] = b->s[i];
  b->s[i-d] = '\0';
  b->len -= d;
}

void div(big_int b1, big_int b2, big_int *q) {
  int sh = b1.len - b2.len, i, count = 0;
  init(q);

  big_int p10;
  char buf10[MAX];
  buf10[0] = '1';
  for (i = 1; i <= sh; i++)
    buf10[i] = '0';
  buf10[i] = '\0';
  init(&p10, buf10);

  shift_r(&b2, sh);
  while (sh >= 0) {
    count = 0;
    while (!sub(b1, b2, &b1)) count++; // while not error
    big_int bc, m;

    init(&bc, count);
    init(&m);
    mult(p10, bc, &m);
    sum(*q, m, q);

    shift_l(&b2, 1);
    sh--;
    shift_l(&p10, 1);
  }

}

void test_sum(const char *s1, const char *s2) {
  big_int a, b, s;
  init(&a, s1);
  init(&b, s2);
  init(&s);

  sum(a, b, &s);
  printf("%s + %s = %s\n", a.s, b.s, s.s);
}

void test_sub(const char *s1, const char *s2) {
  big_int a, b, s;
  init(&a, s1);
  init(&b, s2);
  init(&s);

  sub(a, b, &s);
  printf("%s - %s = %s\n", a.s, b.s, s.s);
}

void test_mult(const char *s1, const char *s2) {
  big_int a, b, s;
  init(&a, s1);
  init(&b, s2);
  init(&s);

  mult(a, b, &s);
  printf("%s x %s = %s\n", a.s, b.s, s.s);
}

void test_div(const char *s1, const char *s2) {
  big_int a, b, s;
  init(&a, s1);
  init(&b, s2);
  init(&s);

  div(a, b, &s);
  printf("%s / %s = %s\n", a.s, b.s, s.s);
}

void calc_bin(ll n, ll k, big_int *r) {
  if (k == 0) {
    init(r, 1);
    return;
  }
  calc_bin(n-1, k-1, r);

  big_int bn, bk;
  init(&bn, n);
  init(&bk, k);

  mult(*r, bn, r);
  div(*r, bk, r);
}

void test_bin(ll n, ll k) {
  big_int s;
  init(&s);

  calc_bin(n, k, &s);
  printf("(%lld  %lld) = %s\n", n, k, s.s);
}

void calc_prob(int i, int j, double p, big_int *prob) {
  double q = 1 - p;
  big_int bp, bq;
  init(&bp, (ll)(p * 100000));
  init(&bq, (ll)(q * 100000));
  init(prob);
  int k, to_k;
  for (k = 1; k < j; k++) {
    big_int qk, bin;
    init(&qk, 1);
    init(&bin);

    for (to_k = 0; to_k < k; to_k++)
      mult(qk, bq, &qk);
    calc_bin(i-1+k, i-1, &bin);
    shift_l(&qk, 5*(k-1)); // coming back to "decimal"

    mult(qk, bin, &qk);
    sum (qk, *prob, prob);
  }

  big_int pk;
  init(&pk, 100000);
  sum(*prob, pk, prob); // sum 1 to prob
  init(&pk, 1);
  for (k = 0; k < i; k++)
    mult(pk, bp, &pk);

  mult(*prob, pk, prob);
  int mod = (prob->len % 5), pos = prob->len - mod;
  if (mod == 0) pos = 5;
  if (prob->s[pos-1] != '0') 
    prob->s[pos] = (char)((((prob->s[pos] - 48) +1) % 10) + 48);
  shift_l(prob, i*5); // coming back to "decimal"

}

// i is the greatest number
void calc_rec(ll i, ll j, big_int *b) {
  big_int tab[2][j+1], *first = &tab[0][0], *second = &tab[1][0], *aux;
  int k, line, col;
  init(&tab[0][0]);
  init(&tab[1][0]);
  for (k = 0; k <= j; k++)
    init(&tab[0][k]);

  for (line = 1; line <= i; line++) {
    for (col = 1; col <= j; col++) {
      big_int two;
      init(&two, 2);
      sum(second[col-1], first[col], &second[col]);
      sum(second[col], two, &second[col]);
    }
    // switch the first with the second row, and continue
    if (line != i) {
      aux = first;
      first = second;
      second = aux;
    }
  }
  copy(b, second[j]);
}

void print_big_int(big_int b) {
  int i;
  for (i = b.len-1; i >= 0; i--)
    printf("%c", b.s[i]);
  printf("\n");
}

void print_big_int_dec(big_int b, int dot) { 
  bool has_int = true;
  int zero_dec = dot - b.len, i;
  if (dot >= b.len)
    has_int = false;

  for (i = b.len -1; i >= dot; i--)
    printf("%c", b.s[i]);

  if (!has_int)
    printf("0");
  printf(".");

  for (i = dot-1; i >= 0; i--)
    if (dot-i <= zero_dec)
      printf("0"); 
    else
      printf("%c", b.s[i]);
  printf("\n");
}

void test_rec(ll a, ll b) {
  big_int s;
  init(&s);

  calc_rec(a, b, &s);
  printf("P(%lld,%lld) = %s\n", a, b, s.s);
}

int main() {
  double p;
  int n;
  bool first = true;
  while (scanf("%lf %d", &p, &n) != EOF) {
    if (n == 0) break;
    big_int prob, rec;
    int k;
    if (!first) printf("\n");
    for (k = 0; k < n; k++) {
      int i, j;
      scanf("%d %d", &i, &j);
      calc_prob(i, j, p, &prob);
      calc_rec(i, j, &rec);
      print_big_int_dec(prob, 5);
      print_big_int(rec);
    }
    first = false;
  }
}

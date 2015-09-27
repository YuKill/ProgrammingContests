#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <math.h>

#define ull unsigned long long
#define MAX 17

// Modify here to get bigger numbers!!
#define NBLK 20

#define PX power10(MAX)

inline ull power10(int n) {
  ull p = 1, m = n +1;
  while (--m > 0)
    p *= 10;
  return p;
}

class big_int {
  ull blk[NBLK];
  int digits;

  void init();
  int get_blk(int) const;
  void att_digits();
  void blk_shift_l(int);
  void blk_shift_r(int);
  void one_digit_mult(int,big_int&) const;
  void copy(const big_int);
  void divide(const big_int, big_int*);

  public:

  big_int();
  big_int(const char*);
  big_int(ull);

  int get_digits() const;
  int get_last_blk() const;
  void get_string(char*) const;
  int get(int) const;
  void shift_l(int); // move to private later
  void shift_r(int); // move to private later

  big_int &operator=(const big_int);
  big_int &operator+=(const big_int);
  big_int &operator-=(const big_int);
  big_int &operator*=(const big_int);
  big_int &operator/=(const big_int);
  big_int &operator%=(const big_int);

  friend bool operator<(const big_int l, const big_int r);

};

// BINARY ARITHMETIC OPERATORS
inline big_int operator+(big_int l, const big_int r) {
  l += r;
  return l;
}

inline big_int operator*(big_int l, const big_int r) {
  l *= r;
  return l;
}

inline big_int operator-(big_int l, const big_int r) {
  l -= r;
  return l;
}

inline big_int operator/(big_int l, const big_int r) {
  l /= r;
  return l;
}

inline big_int operator%(big_int l, const big_int r) {
  l %= r;
  return l;
}

// BINARY COMPARISON OPERATORS
inline bool operator<(const big_int l, const big_int r) {
  if (l.digits < r.digits) return true;
  else if (l.digits > r.digits) return false;

  for (int i = l.get_last_blk(); i >= 0; i--) 
    if (l.blk[i] < r.blk[i]) return true;
    else if (l.blk[i] > r.blk[i]) return false;

  return false;
}

inline bool operator==(const big_int l, const big_int r) {
  if (l < r || r < l) return false;
  return true;
}

inline bool operator>(const big_int l, const big_int r) { return r < l; }
inline bool operator<=(const big_int l, const big_int r) { return (l < r || l == r); }
inline bool operator>=(const big_int l, const big_int r) { return (l > r || l == r); }
inline bool operator!=(const big_int l, const big_int r) { return !(r == l); }


//------------------------------------------------- Private methods

void big_int::init() {
  int i;
  for (i = 0; i < NBLK; i++)
    blk[i] = 0;
  digits = 1;
}

int big_int::get_blk(int n) const {
  int blk = 0;

  // Number of blocks filled
  blk = (n / MAX) - 1;

  // if it is using uncompleted blocks
  if (n % MAX)
    blk++;

  return blk;
}

void big_int::att_digits() {
  bool is_zero = true;

  int i;
  ull msb;
  for (i = NBLK-1; i >= 0; i--)
    if (blk[i] != 0) {
      is_zero = false;
      break;
    }

  // Most Significant Block (msb)
  msb = blk[i];

  digits = 0;
  if (is_zero) digits = 1;
  else {
    while (msb > 0) {
      msb /= 10;
      digits++;
    }
    digits += MAX * i;
  }
}

void big_int::shift_l(int n) {
  if (!n) return;

  int last = get_last_blk(), i, real_sft = n % MAX, blk_shift = n / MAX;
  ull p_frnt_sft = power10(MAX-real_sft), p_back_sft = power10(real_sft),
      shifted = 0;

  for (i = 0; i <= last; i++) {
    ull new_shifted = blk[i] / p_frnt_sft;
    blk[i] = shifted + (p_back_sft * (blk[i] % p_frnt_sft));
    shifted = new_shifted;
  }

  if (shifted) blk[i] = shifted;
  att_digits();

  blk_shift_l(blk_shift);
}

void big_int::blk_shift_l(int n) {
  if (!n) return;
  int last = get_last_blk(), i;

  for (i = last + n; i >= n; i--)
    blk[i] = blk[i-n];
  for (i = 0; i < n; i++)
    blk[i] = 0;
  att_digits();
}

void big_int::shift_r(int n) {
  if (!n) return;
  if (n >= digits) {
    init();
    return;
  }

  int last, i, real_sft = n % MAX, blk_shift = n / MAX;
  ull p_frnt_sft = power10(MAX-real_sft), p_back_sft = power10(real_sft),
      shifted = 0;

  blk_shift_r(blk_shift);
  last = get_last_blk();
  for (i = last; i >= 0; i--) {
    ull new_shifted = blk[i] % p_back_sft;
    blk[i] = (shifted * p_frnt_sft) + (blk[i] / p_back_sft);
    shifted = new_shifted;
  }

  att_digits();
}

void big_int::blk_shift_r(int n) {
  if (!n) return;
  int last = get_last_blk(), i;

  for (i = 0; i <= last; i++) 
    blk[i] = blk[i+n];
  for (i = last; i > last-n; i--)
    blk[i] = 0;
  att_digits();
}

void big_int::one_digit_mult(int d, big_int &mult) const {
  int j, carry = 0;
  ull psafe = power10(MAX-1);

  mult.init();
  for (j = 0; j <= get_last_blk(); j++) {
    ull safe_prod, n;

    safe_prod = blk[j] % psafe;
    safe_prod = (safe_prod * d) + carry;
    carry = safe_prod / psafe;
    safe_prod = safe_prod % psafe;

    n = ((blk[j] / psafe) * d) + carry;
    carry = n / 10;

    mult.blk[j] = ((n % 10) * psafe) + safe_prod;
  }

  if (carry) mult.blk[j] = carry;
  mult.att_digits();
}

void big_int::divide(const big_int r, big_int *mod) {
  if (r > *this) {
    init();
    if (mod != NULL)
      mod->copy(r);
  } else {
    big_int r_sft, result;
    int dig_dif = digits - r.digits, tms = 0;

    r_sft.copy(r);
    r_sft.shift_l(dig_dif);
    while (*this >= r) {
      while (*this >= r_sft) {
        *this -= r_sft;
        tms++;
      }
      big_int times(tms);
      times.shift_l(dig_dif--);
      result += times;

      tms = 0;
      r_sft.shift_r(1);
    }

    if (mod != NULL)
      mod->copy(*this);
    copy(result);
  }
}

void big_int::copy(const big_int r) {
  int last = r.get_last_blk(), i;
  for (i = 0; i <= last; i++)
    blk[i] = r.blk[i];
  digits = r.digits;
}

//------------------------------------------------- Constructors

big_int::big_int() {
  init();
}

big_int::big_int(const char* s) {
  init();

  int len = strlen(s), i, cnt = 0;
  ull p10 = 1;
  for (i = len-1; i >= 0; i--) {
    blk[cnt / MAX] += p10 * (s[i] - '0');

    if (cnt % MAX == MAX-1) p10 = 1;
    else p10 *= 10;
    cnt++;
  }

  digits = len;
}

big_int::big_int(ull n) {
  init();
  blk[0] = n;
  att_digits();
}

//------------------------------------------------- Public methods

int big_int::get_last_blk() const {
  return get_blk(digits);
}

void big_int::get_string(char *s) const {
  int last = get_last_blk(), i;

  char *h = s;
  for (i = last; i >= 0; i--) {

    if (i != last) {
      ull cp = blk[i];
      int len = 0, k;

      while (cp > 0) {
        cp /= 10;
        len++;
      }
      if (!blk[i]) len = 1;

      for (k = 0; k < MAX-len; k++) {
        *h = '0';
        h++;
      }
    }
    sprintf(h, "%llu", blk[i]);
    h += strlen(h);
  }
}

int big_int::get(int i) const {
  int b = get_blk(i +1);
  ull p, blk_i;

  i = i % MAX;
  p = power10(i);

  blk_i = blk[b];
  blk_i /= p;

  return blk_i % 10;
}

int big_int::get_digits() const { return digits; }

//------------------------------------------------- Arithmetic Operators

big_int &big_int::operator=(const big_int r) {
  copy(r);
  return *this;
}

big_int &big_int::operator+=(const big_int r) {
  int i, carry = 0;
  const big_int *gt = this;
  if (digits < r.digits)
    gt = &r;

  for (i = 0; i <= gt->get_last_blk(); i++) {
    ull sum = blk[i] + r.blk[i] + carry;

    carry = sum / PX;
    blk[i] = sum % PX;
  }

  if (carry) blk[i] = carry;

  // Number of digits of the bigger number plus the carry
  // (if it equals one, means that it overflowed in the previous
  // block, and it needs to use one more)
  digits = gt->digits + carry;
}

big_int &big_int::operator-=(const big_int r) {
  if (r > *this) return *this; // still not supported

  int last = get_last_blk(), i, carry = 0;
  for (i = 0; i <= last; i++) {
    int new_carry;
    ull rhs = r.blk[i];

    rhs += carry;
    if (blk[i] < rhs) new_carry = 1;
    else new_carry = 0;

    if (i != last)  // all other blocks beside 'last' are completed
      blk[i] = (new_carry * PX) + blk[i];

    blk[i] -= rhs;
    carry = new_carry;
  }

  att_digits();
  return *this;
}

big_int &big_int::operator*=(const big_int r) {
  big_int mult, result;
  int i, j, carry = 0;

  for (i = 0; i < r.digits; i++) {
    int d = r.get(i);    
    one_digit_mult(d, mult);
    mult.shift_l(i);

    result += mult;
  }

  copy(result);
  return *this;
}

big_int &big_int::operator/=(const big_int r) {
  divide(r, NULL);
  return *this;
}

big_int &big_int::operator%=(const big_int r) {
  big_int mod;
  divide(r, &mod);
  copy(mod);
  return *this;
}

int main() {
  big_int bi("1000000000000000000000000000000000000000000000000000000000000000"),
          bi2(1),
          b;
  char s[100];

  bi = bi - bi2;

  bi.get_string(s);
  printf("%s\n", s);
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define P4 0
#define P15 1
#define P55 2
#define P100 3
#define P400 4

bool div4(char *y, int len) {
  char buf[3];
  buf[2] = '\0';
  buf[0] = y[len-2];
  buf[1] = y[len-1];

  return (atoi(buf) % 4 == 0);
}

bool div100(char *y, int len) {
  return (y[len-1] == '0' && y[len-2] == '0');
}

bool div400(char *y, int len) {
  if (div100(y, len))
    return div4(y, len-2);
}

bool div3(char *y, int len) {
  int i, c = 0;
  for (i = 0; i < len; i++) {
    c += (y[i]-48);
  }
  return (c % 3 == 0);
}

bool div5(char *y, int len) {
  return (y[len-1] == '0' || y[len-1] == '5');
}

bool div11(char *y, int len) {
  int even = 0, odd = 0, i;
  for (i = 0; i < len; i++) {
    if (i % 2 == 0)
      even += (y[i]-48);
    else
      odd += (y[i]-48);
  }
  return ((even-odd) % 11 == 0);
}

bool div15(char *y, int len) {
  return (div5(y, len) && div3(y, len));
}

bool div55(char *y, int len) {
  return (div5(y, len) && div11(y, len));
}

bool div(char *y, int m) {
  int len = strlen(y);
  if (m == P4)
    return div4(y, len);
  else if (m == P100)
    return div100(y, len);
  else if (m == P400)
    return div400(y, len);
  else if (m == P15)
    return div15(y, len);
  else
    return div55(y, len);
}

int main() {
  char year[100000];
  bool flag = false;

  while (scanf("%s", year) != EOF) {
    int i;
    bool divs[5], leap = true, h = false, b = false;
    
    for (i = 0; i < 5; i++)
      divs[i] = div(year, i);

    if ((divs[P4] && divs[P100] && !divs[P400]) || !divs[P4])
      leap = false;
    if (divs[P15])
      h = true;
    if (leap && divs[P55])
      b = true;

    if (flag) printf("\n");
    if (leap)
      printf("This is leap year.\n");
    if (h)
      printf("This is huluculu festival year.\n");
    if (b)
      printf("This is bulukulu festival year.\n");
    if (!leap && !h && !b)
      printf("This is an ordinary year.\n");

    flag = true;
  }
}

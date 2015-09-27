#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
  for (char s[5]; scanf("%s", s) != EOF && ((s[0]-'0') || 
        (s[1]-'0') || (s[3]-'0'));) {
    int n = (((s[0]-'0')*10) + s[1]-'0') * pow(10, s[3]-'0');
    int start = 1, delta = 2, size = n;

    while (delta <= size) {
      if (size % delta) { // passou
        start += delta;
      } 
      size -= (size % delta);
      delta *= 2;
    }



    printf("%d\n", start);
  }
}

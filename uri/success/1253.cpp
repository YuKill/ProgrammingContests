#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int mod26(int a) {
  if (a >= 0) return a%26;
  return a+26;
}

int main() {
  int tests;
  scanf("%d", &tests);

  for (int t = 0; t < tests; t++) {
    int n;
    char buf[64];
    scanf("%s\n%d", buf, &n);

    int len = strlen(buf);
    for (int i = 0; i < len; i++) 
      buf[i] = mod26(buf[i]-'A'-n) + 'A';
  
    printf("%s\n", buf);
  }
}

#include <cstdlib>
#include <cstdio>

int main() {
  for (int m; scanf("%d", &m) != EOF && m;) {
    int ch[128];
    char buf[1000001];
    
    for (int i = 0; i < 128; i++) ch[i] = 0;

    buf[0] = '\0';
    int i;
    for (i = 0; buf[i] != '\n'; i++)
      scanf("%c", &buf[i]);
    buf[i] = '\0';

  }
}

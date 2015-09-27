#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
  char buf[64];
  int base_proc;

  while (scanf("%s\n%d", buf, &base_proc) != EOF) {
    int proc = 0, len = strlen(buf), cnt = 0;
    for (int i = 0; i < len; i++) {
      if (buf[i] == 'W') {
        cnt++;
        proc = base_proc;
      } else {
        if (!proc) {
          cnt++;
          proc = 1;
        } else {
          if (proc == base_proc) {
            cnt++;
            proc = 1;
          } else proc++;
        }
      }
    }

    printf("%d\n", cnt);
  }

}

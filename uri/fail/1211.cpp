#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct entry {
  char *number;
  entry *next;
} entry;

void insert(entry *&t, char *n) {
  t->next = new entry;
  t = t->next;
  t->number = n;
}

int main() {
  for (int n; scanf("%d", &n) != EOF && n; ) {
    char tel[n][256];
    for (int i = 0; i < n; i++)
      scanf("%s", &tel[i][0]);

    entry *t = new entry;

    int cnt = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < 256; j++) {
        if (tel[i-1][j] == '\0' || tel[i][j] == '\0' ||
          tel[i-1][j] != tel[i][j]) break;
        cnt++;
      }
    }

    printf("%d\n", cnt);
  }
}

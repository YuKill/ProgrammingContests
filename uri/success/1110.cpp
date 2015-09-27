#include <stdlib.h>
#include <stdio.h>

typedef struct elem {
  int n;
  elem *r;
  elem() {r = NULL;}
} elem;

void insert(elem *&t, int n) {
  t->r = new elem;
  t->r->n = n;
  t = t->r;
}

int remove(elem *&h) {
  int x = h->n;
  elem *q = h;
  h = h->r;
  delete q;
  return x;
}

int main() {
  for (int n; scanf("%d", &n) != EOF && n; ) {
    elem *h = new elem, *t = h;

    h->n = 1;
    for (int i = 2; i <= n; i++) insert(t, i);

    printf("Discarded cards: ");
    
    int cnt = 2;
    printf("%d", remove(h));
    while (h->r != NULL) {
      if (cnt % 2) {
        printf(", %d", remove(h));
      } else {
        insert(t, remove(h));
      }
      cnt++;
    }

    printf("\nRemaining card: %d\n", h->n);
  }
}

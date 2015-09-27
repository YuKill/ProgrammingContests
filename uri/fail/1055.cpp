#include <stdlib.h>
#include <stdio.h>

typedef struct number {
  int n;
  number *l, *r;
  void init() { 
    n = 0; 
    l = NULL;
    r = NULL;
  };

  number() {
    init();
  };

  void push_back(number *a) {
    number *q = this;
    while (q->l) q = q->l;
    q->l = a;
    a->r = q;
  };

  void push_front(number *a) {
    number *q = this;
    while (q->r) q = q->r;
    q->r = a;
    a->l = q;
  };

} number;

int get_max(int v[], int *i) {
  for (; *i >= 0; *i -= 1) {
    if (v[*i]) {
      v[*i]--;
      break;
    }
  }
  return *i;
}

int get_min(int v[], int *i) {
  for (; *i <= 1000; *i += 1) {
    if (v[*i]) {
      v[*i]--;
      break;
    }
  }
  return *i;
}

void copy(int dst[], int src[]) {
  for (int i = 0; i <= 1000; i++) dst[i] = src[i];
}

int main() {
  int tests;
  scanf("%d", &tests);

  for (int t = 0; t < tests; t++) {
    int n;
    scanf("%d", &n);

    int v[1001], bck_up[1001];
    for (int i = 0; i <= 1000; i++) v[i] = 0;
    for (int i = 0, tmp; i < n; i++) {
      scanf("%d", &tmp);
      v[tmp]++;
    }

    copy(bck_up, v);
    int sum[2];
    for (int it = 0; it < 2; it++) {
      int front = 0, back = 0, cnt = 0, i = 0, j = 1000;
      bool begin_min = (it == 0) ? true : false;
      int eq = (begin_min) ? 1 : 3;

      number numbers[n];

      while (cnt != n) {
        int next;

        if (begin_min && eq <= 2) next = get_min(v, &i);
        else next = get_max(v, &j);

        if (!cnt) {
          front = next;
          back = next;
        } else if (abs(next-front) > abs(next-back)) {
          numbers[0].push_front(&numbers[cnt]);
          front = next;
        } else {
          numbers[0].push_back(&numbers[cnt]);
          back = next;
        }
        
        eq--;
        if (!eq) eq = 4;
        begin_min = true;
        numbers[cnt++].n = next;
      }

      copy(v, bck_up);
      number *h = &numbers[0];
      while (h->l) h = h->l;

      printf("%d ", h->n);
      h = h->r;
      sum[it] = 0;
      for (int s = 1; s < n; s++) {
        sum[it] += abs(h->l->n - h->n);
        printf("%d ", h->n);
        h = h->r;
      }
      printf("\n");
    }

    int index = (sum[0] > sum[1]) ? 0 : 1;
    printf("Case %d: %d\n", t+1, sum[index]);
  }
}

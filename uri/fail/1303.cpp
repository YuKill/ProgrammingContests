#include <stdlib.h>
#include <stdio.h>

typedef struct team {
  int id, shoots, shoots_a, pt;
  team() { shoots = 0; shoots_a = 0; pt = 0; }

  double get_avg() {
    return (double)shoots/(double)shoots_a;
  }
} team;

void swap(int clas[], int i, int j) {
  int aux = clas[i];
  clas[i] = clas[j];
  clas[j] = aux;
}

int main() {
  for (int n, t = 1; scanf("%d", &n) != EOF && n; t++) {
    int n_games = ((n*(n-1))/2);
    team teams[n+1];

    int clas[n];
    for (int i = 0; i < n; i++) { 
      teams[i+1].id = i+1;
      clas[i] = teams[i+1].id; 
    }

    for (int i = 0; i < n_games; i++) {
      int ta[2], tb[2];
      scanf("%d %d %d %d", &ta[0], &ta[1], &tb[0], &tb[1]);
      int *tw = ta, *tl = tb;

      if (ta[1] < tb[1]) {
        tw = tb;
        tl = ta;
      }

      team *win = &teams[tw[0]], *los = &teams[tl[0]];

      win->shoots += tw[1];
      win->shoots_a += tl[1];
      win->pt += 2;

      los->shoots += tl[1];
      los->shoots_a += tw[1];
      los->pt += 1;

      int j;
      for (j = 0; j < n; j++)
        if (clas[j] == win->id) break;

      if (j != 0)
        while (win->pt > teams[clas[j-1]].pt) {
          swap(clas, j, j-1);
          j--;
        }

      for (j = 0; j < n; j++)
        if (clas[j] == los->id) break;

      if (j != 0)
        while (los->pt > teams[clas[j-1]].pt) {
          swap(clas, j, j-1);
          j--;
        }
    }

    int max_pt = teams[clas[0]].pt;
    for (int i = 1; i < n; i++) {
      if (teams[clas[i]].pt != max_pt) break;
      int k = i;
      for (int j = i-1; j >= 0; j--) {
        if (teams[clas[k]].get_avg() > teams[clas[j]].get_avg()) {
          swap(clas, k, j);
          k--;
        }
      }
    }

    double max_avg = teams[clas[0]].get_avg();
    for (int i = 1; i < n; i++) {
      if (teams[clas[i]].get_avg() != max_avg) break;
      int k = i;
      for (int j = i-1; j >= 0; j--) {
        if (teams[clas[k]].shoots > teams[clas[j]].shoots) {
          swap(clas, k, j);
          k--;
        }
      }
    }

    int shoots = teams[clas[0]].shoots;
    for (int i = 1; i < n; i++) {
      if (teams[clas[i]].shoots != shoots) break;
      int k = i;
      for (int j = i-1; j >= 0; j--) {
        if (teams[clas[k]].id < teams[clas[j]].id) {
          swap(clas, k, j);
          k--;
        }
      }
    }

    printf("Instancia %d\n", t);
    for (int i = 0; i < n; i++) {
      if (i != 0) printf(" ");
      printf("%d", clas[i]);
    }
    printf("\n");
  }
}

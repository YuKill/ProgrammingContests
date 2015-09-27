#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <cfloat>

using namespace std;

typedef struct par {
  int piz, price;
  par(int p, int pr) {
    piz = p;
    price = pr;
  }
} par;

typedef map<int, vector<par> > t_map;
double calculate(int ans[], int k, double d[], int a[], int p[]) {
  double area = 0, price = 0;
  for (int i = 0; i < k; i++) {
    area += a[ans[i]];
    price += (p[ans[i]] * d[ans[i]]);
  }
  return price/area;
}

double backtrack(int ans[], int k, int start, int m, int a[], int p[], t_map ticket, double d[]) {
  if (start == m) return calculate(ans, k, d, a, p);
  double min = DBL_MAX;
  for (int i = start; i < m; i++) {
    ans[k] = i;
    for (vector<par>::iterator t = ticket[i].begin(); t != ticket[i].end(); t++)
      d[t->piz] *= (1-((double)t->price/100.0));
    double new_calc = backtrack(ans, k+1, i+1, m, a, p, ticket, d);
    if (new_calc < min) min = new_calc;
    for (vector<par>::iterator t = ticket[i].begin(); t != ticket[i].end(); t++)
      d[t->piz] /= (1-((double)t->price/100.0));
  }
  double new_calc;
  if (k > 0) {
    new_calc = calculate(ans, k, d, a, p);
    min = (min < new_calc) ? min : new_calc;
  }
  return  min;
}

int main() {
  for (int m; scanf("%d", &m) != EOF && m;) {
    int a[m], p[m], n[m];
    double d[m];
    t_map tickets;

    for (int i = 0; i < m; i++) {
      scanf("%d %d %d", &p[i], &a[i], &n[i]);
      for (int j = 0; j < n[i]; j++) {
        int ai, pi;
        scanf("%d %d", &ai, &pi);
        par p(ai-1, pi);
        tickets[i].push_back(p);
      }
      d[i] = 1;
    }

    int ans[m];
    printf("%.4f\n", backtrack(ans, 0, 0, m, a, p, tickets, d));

  }
}

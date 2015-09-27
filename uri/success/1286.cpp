#include <stdlib.h>
#include <stdio.h>

typedef struct orders {
  int pizza, time;
  orders() {
    pizza = 0;
    time = 0;
  }
  orders &operator=(orders o) {
    pizza = o.pizza;
    time = o.time;
    return *this;
  }
} orders;

int max(int a, int b) {
  return (a > b) ? a : b;
}

int main() {
  for (int n, p; scanf("%d", &n) != EOF && n;) {
    scanf("%d", &p);

    orders ord[n]; 

    for (int i = 0; i < n; i++)
      scanf("%d %d", &ord[i].time, &ord[i].pizza);

    orders m[n+1][p+1];
    // initialize

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= p; j++) {
        m[i][j] = m[i-1][j];
        int pizzas = ord[i-1].pizza,
            tmp = ord[i-1].time;

        if (j >= pizzas && m[i-1][j-pizzas].pizza + pizzas <= j) {
          m[i][j].time = max(m[i][j].time, m[i-1][j-pizzas].time + tmp);
          m[i][j].pizza = pizzas + m[i-1][j-pizzas].pizza;
        }
      }
    }

    printf("%d min.\n", m[n][p].time);
  }
}

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
  int r, h, w, c = 1;

  while (scanf("%d", &r) != EOF) {
    if (r == 0) break;
    scanf("%d %d", &h, &w);

    double r_pizza;
    r_pizza = sqrt(h*h + w*w);

    if (2*r >= r_pizza)
      printf("Pizza %d fits on the table.\n", c);
    else
      printf("Pizza %d does not fit on the table.\n", c);

    c++;
  }
}

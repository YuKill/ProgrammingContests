#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct bola {
  int x, y;
};

int main() {
  int testes, i;
  scanf("%d", &testes);

  for (i = 0; i < testes; i++) {
    int n, j, r, menor = 99999999, h_int;
    scanf("%d", &n);

    bola bola_branca;
    scanf("%d %d", &bola_branca.x, &bola_branca.y);

    bola bola;
    for (j = 0; j < n; j++) {
      scanf("%d %d", &bola.x, &bola.y);
      double x = fabs(bola_branca.x - bola.x);
      double y = fabs(bola_branca.y - bola.y);
      double h = sqrt(x*x + y*y);

      h_int = h*10000;
      if (menor > h_int) {
        menor = h_int;
        r = j+1;
      }
    }
    printf("%d\n", r);
  }
}

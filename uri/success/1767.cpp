#include <stdlib.h>
#include <stdio.h>

#define W 50

typedef struct trip {
  int pkgs;
  int qt;
  int w;
  void init() {
    pkgs = 0;
    qt = 0;
    w = 0;
  };
} trip;

int main() {
  int tests;
  scanf("%d", &tests);

  for (int t = 0; t < tests; t++) {
    int pac;
    scanf("%d", &pac);

    int qt[pac], w[pac];
    for (int i = 0; i < pac; i++) 
      scanf("%d %d", &qt[i], &w[i]);

    trip m[pac+1][W+1];
    for (int i = 0; i <= pac; i++) m[i][0].init();
    for (int i = 0; i <= W; i++) m[0][i].init();

    for (int i = 1; i <= pac; i++) {
      for (int j = 1; j <= W; j++) {
        int do_not_place = m[i-1][j].qt, 
            place = m[i-1][j-w[i-1]].qt + qt[i-1];

        m[i][j].qt = do_not_place;
        m[i][j].pkgs = m[i-1][j].pkgs;
        m[i][j].w = m[i-1][j].w;

        if (j >= w[i-1] && place >= do_not_place) {
          m[i][j].qt = place;
          m[i][j].pkgs = m[i-1][j-w[i-1]].pkgs + 1;
          m[i][j].w = m[i-1][j-w[i-1]].w + w[i-1];
        }
      }
    }

    printf("%d brinquedos\n", m[pac][W].qt);
    printf("Peso: %d kg\n", m[pac][W].w);
    printf("sobra(m) %d pacote(s)\n", pac - m[pac][W].pkgs);

    printf("\n");
  }
}

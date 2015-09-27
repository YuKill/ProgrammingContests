#include <stdlib.h>
#include <stdio.h>
#include <string>

#define OK 1
#define POW 0
#define W 1

int max(int a, int b) {
  if (a > b) return a;
  else return b;
}

int destroy(int n, int p[][2], int c, int r) {
  int m[n+1][c+1];
  for (int i = 0; i <= n; i++)
    m[i][0] = 0;
  for (int j = 0; j <= c; j++)
    m[0][j] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= c; j++) {
      if (p[i-1][W] <= j) {
        m[i][j] = max(m[i-1][j],m[i-1][j-p[i-1][W]] + p[i-1][POW]);
      } else {
        m[i][j] = m[i-1][j];
      }
      if (m[i][j] >= r) return OK;
    }
  }

  return (m[n][c] >= r);
}

int main() {

    int test;
    scanf("%d", &test);

    for (int i = 0; i < test; i++) {

        int n;
        scanf("%d", &n);

        int p[n][2];
        for (int j = 0; j < n; j++) 
            scanf("%d %d", &p[j][0], &p[j][1]);

        int c;
        scanf("%d", &c);

        int r;
        scanf("%d", &r);

        int result = destroy(n, p, c, r);

        if (result)
            printf("Missao completada com sucesso\n");
        else
            printf("Falha na missao\n");
    }

}

#include <stdlib.h>
#include <stdio.h>

bool over(int vet[]) {
  for (int i = 0; i < 5; i++)
    if (vet[i]) return false;
  return true;
}

int main() {
  int l[5];
  int v[5][1001];

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 1001; j++)
      v[i][j] = 0;

  for (int i = 0; i < 5; i++) {
    scanf("%d", &l[i]);
    for (int j = 0; j < l[i]; j++) {
      int custo;
      scanf("%d", &custo);
      v[i][j]
    }
  }

  int sum = 0, cnt[5];
  bool ok[5];

  for (int i = 0; i < 5; i++) {
    ok[i] = false;
    cnt[i] = 1000;
  }

  while (!over(cnt))
    for (int i = 0; i < 5; i++) {
      while (v[i][cnt[i]]) cnt[i]++;
      if (!ok[i]) {
        ok[i] = true;
      }
    }
  }
}

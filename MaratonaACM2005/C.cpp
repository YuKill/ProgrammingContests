#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int *to;

int comp(const void *a, const void *b) {
  return to[*(int*)a] - to[*(int*)b];
}

int bin_search(int i, int start, int end, int *ordered, int *from) {
  if (start > end) {
    return end;
  }
  int mid = start + ((end-start)/2);
  if (to[ordered[mid]] > from[ordered[i]])
    return bin_search(i, start, mid-1, ordered, from);
  else if (to[ordered[mid]] < from[ordered[i]])
    return bin_search(i, mid+1, end, ordered, from);
  return mid;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

int main() {
  for (int n; scanf("%d", &n) != EOF && n;) {
    int point[n];
    int week[n];
    int from[n];
    int ordered[n];
    int optimal[n];
    int last_in[n];

    to = (int*) malloc(sizeof(int) * n);
    for (int i = 0, id, from_[2], to_[2]; i < n; i++) {
      char wkDay[4];
      scanf("%d %d %s %d:%d %d:%d",
          &id, &point[i], wkDay, &from_[0], &from_[1],
          &to_[0], &to_[1]);
      if (!strcmp(wkDay, "Seg"))
        week[i] = 0;
      else if (!strcmp(wkDay, "Ter"))
        week[i] = 1;
      else if (!strcmp(wkDay, "Qua"))
        week[i] = 2;
      else if (!strcmp(wkDay, "Qui"))
        week[i] = 3;
      else 
        week[i] = 4;
      
      from[i] = ((week[i] * 24) + from_[0]) * 60 + from_[1];
      to[i] = ((week[i] * 24) + to_[0]) * 60 + to_[1];
      ordered[i] = i;
    }

    qsort((void*) ordered, n, sizeof(int), comp);
    for (int i = 0; i < n; i++)
      printf("%d ", ordered[i]);
    printf("\n");

    optimal[0] = point[ordered[0]];
    last_in[0] = -1;
    for (int i = 1; i < n; i++) {
      int t = bin_search(i, 0, n-1, ordered, from);
      if (t != -1)
        optimal[i] = max(optimal[i-1], optimal[t] + point[ordered[i]]);
      else
        optimal[i] = max(optimal[i-1], point[ordered[i]]);
      last_in[i] = (optimal[i] == optimal[i-1]) ? i-1 : t; 
    }

    int week_point[5];
    int i = n-1;
    for (int i = 0; i < 5; i++) week_point[i] = 0;
    while (i != -1) {
      if (last_in[i] != i-1 || optimal[i] != optimal[i-1])
        week_point[week[ordered[i]]] += point[ordered[i]];
      i = last_in[i];
    }
    
    printf("Total de pontos: %d\n", optimal[n-1]);
    printf("Seg: %d\n", week_point[0]);
    printf("Ter: %d\n", week_point[1]);
    printf("Qua: %d\n", week_point[2]);
    printf("Qui: %d\n", week_point[3]);
    printf("Sex: %d\n", week_point[4]);
    free(to);
  }
}

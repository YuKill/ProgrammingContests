#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct reindeer {
  char name[128];
  int w, age;
  double height;
} reindeer;

int comp_weight(const void *a, const void *b) {
  reindeer *l = (reindeer*)a, *r = (reindeer*)b;
  return (r->w - l->w);
}

int comp_age(const void *a, const void *b) {
  reindeer *l = (reindeer*)a, *r = (reindeer*)b;
  return (l->age - r->age);
}

int comp_height(const void *a, const void *b) {
  reindeer *l = (reindeer*)a, *r = (reindeer*)b;
  return (l->height - r->height);
}

int comp_name(const void *a, const void *b) {
  reindeer *l = (reindeer*)a, *r = (reindeer*)b;
  return strcmp(l->name, r->name);
}

void print(reindeer all[], int n) {
  printf("{");
  for (int i = 0; i < n; i++) {
    if (i != 0) printf(",");
    printf("%s", all[i].name);
  }
  printf("}\n");
}

int main() {
  int tests;
  scanf("%d", &tests);

  for (int t = 1; t <= tests; t++) {
    int n, m;
    scanf("%d %d", &n, &m);

    reindeer all[n];
    for (int i = 0; i < n; i++)
      scanf("%s %d %d %lf", all[i].name, &all[i].w, &all[i].age, &all[i].height);

    qsort((void*)&all[0], n, sizeof(reindeer), comp_weight);
    int w = all[0].w, i = 1;
    while (all[i].w == w) i++;

    if (i > 1) {
      qsort((void*)&all[0], i, sizeof(reindeer), comp_age);
      int age = all[0].age;
      i = 1;
      while (all[i].age == age && all[i].w == w) i++;

    
      if (i > 1) {
        qsort((void*)&all[0], i, sizeof(reindeer), comp_height);
        double height = all[0].height;
        i = 1;
        while (all[i].height == height && all[i].age == age && all[i].w == w) i++;

        if (i > 1) {
          qsort((void*)&all[0], i, sizeof(reindeer), comp_name);
        }
      }
    }

    printf("CENARIO {%d}\n", t);
    for (int i = 0; i < m; i++)
      printf("%d - %s\n", i+1, all[i].name);
  }

}

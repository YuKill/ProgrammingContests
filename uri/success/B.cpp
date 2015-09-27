#include <stdlib.h>
#include <stdio.h>

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

typedef struct activity {
  int w, f, s;
} activity;

int compare(const void* p1, const void *p2) {
  return (((activity*) p1)->f - ((activity*) p2)->f);
}

int searchBefore(int i, activity *act, int s, int f) {
  if (s >= f) {
    if (act[s].f <= act[i].s) return s+1;
    else return s;
  }

  int pivot = s+((f-s)/2), ans;
  if (act[pivot].f > act[i].s)
    ans = searchBefore(i, act, s, pivot-1);
  else if (act[pivot].f == act[i].s) 
    ans = pivot;
  else 
    ans = searchBefore(i, act, pivot+1, f);

  return ans;
}

int searchLin(int i, activity *act) {
  for (int k = i-1; k >= 0; k--) {
    if (act[k].f <= act[i].s)
      return k+1;
  }
  return 0;
}

int main() {
  int req;
  scanf("%d", &req);

  activity act[req];
  for (int i = 0; i < req; i++) {
    scanf("%d %d", &act[i].s, &act[i].f);
    act[i].w = act[i].f - act[i].s ;
  }

  qsort(act, req, sizeof(activity), compare);

  int cost[req+1];
  cost[0] = 0;
  for (int i = 1; i <= req; i++) {
//    int t = searchBefore(i-1, act, 0, i-2);
    int t = searchLin(i-1, act);
    cost[i] = max(cost[i-1], cost[t] + act[i-1].w);
  }

  printf("%d\n", cost[req]);
}

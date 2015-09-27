#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include <vector>
#include <unordered_map>

using namespace std;

int calc_dist(unordered_map<char*,vector<char*> > graph, int n, char *src, char *dst) {
  vector<char*> q;
  unordered_map<char*, int> w, visited;
  for (auto& i : graph) {
    char *p = i.first;
    w[p] = 1;
    visited[p] = 0;
    printf("%s w:%d v:%d\n", p, w[p], visited[p]);
  }
 
 q.push_back(src);
  while (!q.empty()) {
    char *v = q.back();
    q.pop_back();
    for (vector<char*>::iterator i = graph[v].begin(); i != graph[v].end(); i++) {
      char *p = *i;
      if (!visited[p]) {
        w[p] = w[v]+1;
        visited[p] = 1;
        q.push_back(p);
      }
    }
  }
  return w[dst];
}

int main() {
  int v, e;
  scanf("%d %d", &v, &e);

  unordered_map<char*, vector<char*> > graph;
  for (int i = 0; i < e; i++) {
    char v1[100], v2[100];
    scanf("%s %s", v1, v2);
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
  }

  for (auto &i : graph) printf("%s\n", i.first);

  int dist;
  dist = calc_dist(graph, v, "Entrada", "*");
  dist +=calc_dist(graph, v, "*", "Saida");
  dist--;

  printf("%d\n", dist);
}

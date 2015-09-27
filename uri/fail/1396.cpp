#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

int max(int a, int b) { return (a > b) ? a :b; }

int main() {
  for (int n, k, c = 1; scanf("%d %d", &n, &k) != EOF && n|k; c++) {
    char offset;
    scanf("%c", &offset);

    std::string q[n+1];
    for (int i = 1; i <= n-1; i++) {
      std::getline(std::cin, q[i], ' ');
    }
    std::getline(std::cin, q[n], '\n');

    std::vector<std::string> vec(q+1, q+n+1);
    std::sort(vec.begin(), vec.end());

    std::map<std::string, int> pos;
    for (int i = 0; i < n; i++)
      pos[vec[i]] = i;
  

    int m[n+1][k+1];
    for (int i = 0; i <= k; i++)
      m[1][i] = 1;
    for (int i = 2; i <= n; i++) {
      m[i][0] = 1;
      if (pos[q[i]] > pos[q[i-1]])
        m[i][0] += m[i-1][0];
    }

    for (int j = 1; j <= k; j++) {
      int best = 0, a,b;
      for (int i = 2; i <= n; i++) {
        m[i][j] = max(m[i-1][j], m[i][j-1]);
        if (pos[q[i]] < pos[q[i-1]]) {
          int swap = 2;
          for (int l = i-2; l > 0; l--) {
            if (pos[q[i]] < pos[q[l]]) break;
            else swap++;
          }
          if (swap >= m[i][j]) {
            m[i][j] = swap;
            if (m[i][j] >= best) {
              best = m[i][j];
              a = i;
              b = i-1;
            }
          }
        } else {
          m[i][j] = m[i-1][j] + 1;  
        }

      }
      std::string aux = q[a];
      q[a] = q[b];
      q[b] = aux;
    }

    printf("Instancia: %d\n", c);
    for (int i = 1; i <= n; i++)
      printf("%d-%s ", i, q[i].c_str());
    printf("\n\n");
  }
}

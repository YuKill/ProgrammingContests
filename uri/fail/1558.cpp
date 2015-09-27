#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {

  int n;

  while (scanf("%d", &n) != EOF) {

    double sq = sqrt(double(n));
    int flag = 0;

    for (int i = 0; i <= int(sq); i++) {
      for (int j = 0; j <= int(sq); j++) {
        int x = i * i;
        int y = j * j;
        if (x + y == n) flag = 1;
        if (flag == 1) break;
      }
      if (flag == 1) break;
    }
        
    if (flag == 1) printf("YES\n");
    else printf("NO\n");
  }

}

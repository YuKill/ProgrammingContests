#include <stdlib.h>
#include <stdio.h>

int main() {
  for (int n, d; scanf("%d %d", &n, &d) != EOF && (n|d); ) {
    int presence[n];
    
    for (int i = 0; i < n; i++) presence[i] = 0;
    for (int i = 0; i < d; i++) 
      for (int j = 0, xi; j < n; j++) {
        scanf("%d", &xi);
        presence[j] += xi;
      }
    
    bool exist = false;
    for (int i = 0; i < n; i++)
      if (presence[i] == d) {
        exist = true;
        break;
      }

    if (exist) printf("yes\n");
    else printf("no\n");
  }
}

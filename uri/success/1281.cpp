#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
  int tests;
  scanf("%d", &tests);
  for (int t = 1; t <= tests; t++) {
    int nf;
    scanf("%d", &nf);
    
    char food[nf][64];
    double price[nf];

    for (int i = 0; i < nf; i++)
      scanf("%s %lf", &food[i][0], &price[i]);

    int no;
    scanf("%d", &no);
    double total = 0;
    for (int i = 0, qt; i < no; i++) {
      char what[64];
      scanf("%s %d", what, &qt);
      
      for (int j = 0; j < nf; j++) {
        if (!strcmp(what, &food[j][0]))
          total += (qt * price[j]);
      }
    }

    printf("R$ %.2f\n", total);
  }
}

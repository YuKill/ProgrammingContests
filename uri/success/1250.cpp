#include <stdlib.h>
#include <stdio.h>

int main() {
  int tests;
  scanf("%d", &tests);

  for (int t = 0; t < tests; t++) {
    int shots;
    scanf("%d", &shots);

    int height[shots];
    char action[shots+1];

    for (int i = 0; i < shots; i++)
      scanf("%d", &height[i]);
    scanf("%s", action);

    int hit = 0;
    for (int i = 0; i < shots; i++)  
      if (height[i] <= 2 && action[i] == 'S') hit++;
      else if (height[i] > 2 && action[i] == 'J') hit++;

    printf("%d\n", hit);
  }
}

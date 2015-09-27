#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main() {
  for (int n; scanf("%d", &n) != EOF; ) {
    int size[101];
    for (int i = 0; i <= 100; i++) size[i] = 0;
    for (int i = 0, from, to; i < n; i++) {
      scanf("%d %d", &from, &to);
      for (int j = from; j <= to; j++) 
        size[j]++;      
    }

    int num;
    scanf("%d", &num);

    int cnt = 0;
    for (int i = 0; i < num; i++) {
      if (size[i])
        cnt += size[i];
    }

    if (size[num]) 
      printf("%d found from %d to %d\n", num, cnt, cnt+size[num]-1);
    else
      printf("%d not found\n", num);    
  }
}

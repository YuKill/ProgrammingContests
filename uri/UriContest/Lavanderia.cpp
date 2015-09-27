#include <stdlib.h>
#include <stdio.h>

int main() {
  int n, la, lb, sa, sb;
  scanf("%d %d %d %d %d", &n, &la, &lb, &sa, &sb);

  bool l = false, s = false;
  for (int i = 1; i <= n; i++) {
    if (n >= la*i && n <= lb*i)
      l = true;
    if (n >= sa*i && n <= sb*i)
      s = true;
  }
  if (s && l)
    printf("possivel\n");
  else
    printf("impossivel\n");
}

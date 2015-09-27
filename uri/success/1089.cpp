#include <cstdlib>
#include <cstdio>

int main() {
  for (int n; scanf("%d", &n) != EOF && n;) {
    int loop[n], cnt = 0;
    for (int i = 0; i < n; i++) 
      scanf("%d", &loop[i]);

    for (int i = 1; i <= n; i++) {
      if ((loop[i%n] > loop[i-1] && loop[i%n] > loop[(i+1)%n]) ||
        (loop[i%n] < loop[i-1] && loop[i%n] < loop[(i+1)%n]))
        cnt++;
    }

    printf ("%d\n", cnt);
  }
}

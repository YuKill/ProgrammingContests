#include <cstdlib>
#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);

  int numbers[2001];
  for (int i = 0; i <= 2000; i++) numbers[i] = 0;
  for (int i = 0, numb; i < n; i++) {
    scanf("%d", &numb);
    numbers[numb]++;
  }

  for (int i = 0; i <= 2000; i++) {
    if (!numbers[i]) continue;
    printf("%d aparece %d vez(es)\n", i, numbers[i]);
  }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ll long long

int main() {
  int I, J;
  char Line[1000001];
  scanf("%s", Line);

  ll SubsThree = 0;

  int Length = strlen(Line);
  int Mod[] = { 0, 0, 0 };
  for (I = 0; I < Length; ++I) {
    if (isdigit(Line[I])) {
      int Aux;
      int M = (Line[I] - '0') % 3;
      if (!M) {
        Mod[0] += 1;
      } else if (M == 1) {
        Aux = Mod[0];
        Mod[0] = Mod[2];
        Mod[2] = Mod[1];
        Mod[1] = Aux + 1;
      } else {
        Aux = Mod[0];
        Mod[0] = Mod[1];
        Mod[1] = Mod[2];
        Mod[2] = Aux + 1;
      }
      SubsThree += Mod[0];
    } else {
      Mod[0] = 0;
      Mod[1] = 0;
      Mod[2] = 0;
    }
  }

  printf("%lld\n", SubsThree);

  return 0;
}

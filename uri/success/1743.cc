#include <cstdio>
#include <iostream>

int main() {
  int entrada[5];
  int saida[5];
  bool encaixa = true;
  for(int i = 0; i < 5; i++){
    scanf("%d", &entrada[i]);
  }
  for (int i = 0; i < 5; i++){
    scanf("%d", &saida[i]);
  }
  for (int i = 0; i < 5; i++){
    if (entrada[i] == saida[i])
      encaixa = false;
  }
  if (encaixa){
    printf("Y\n");
  } else {
    printf("N\n");
  }
}

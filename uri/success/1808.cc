#include <cstdio>
#include <iostream>
#include <string>

int main() {
  double total = 0;
  double qtnotas = 0;
  char a, aux;
  while (scanf("%c", &a) != EOF){
    pog:
    if (a == '1'){
      scanf("%c", &aux);
      if (aux == '0'){
        total += 10;
        qtnotas++;
      } else {
        total += 1;
        qtnotas++;
        a = aux;
        goto pog;
      }
    } else if (a != '\n') {
      total += a - 48;
      qtnotas++;
    }
  }
  double media = total / qtnotas;
  printf("%.2lf\n", media);
}

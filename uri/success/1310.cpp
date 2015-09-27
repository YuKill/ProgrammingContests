#include <stdlib.h>
#include <stdio.h>

using namespace std;

int calc_lucro(int custo, int rec[], int ndays) {
    
    int lucro_max = 0, lucro_ant = 0;
    for (int i = 0; i < ndays; i++) {
        
        lucro_ant += (rec[i] - custo);
        if (lucro_ant < 0) {

            lucro_ant = 0;
            continue;
        } else if (lucro_ant > lucro_max) {

            lucro_max = lucro_ant;
        }
    }

    return lucro_max;
}

int main() {
    
    int ndays;

    while (scanf("%d", &ndays) != EOF) {
        
        int custo;
        scanf("%d", &custo);

        int i;
        int rec[ndays];
        for (i = 0; i < ndays; i++) {

            scanf("%d", &rec[i]);
        }

        int lucro = calc_lucro(custo, rec, ndays);
        printf("%d\n", lucro);
    }

}

#include <stdlib.h>
#include <stdio.h>

int decide_x(int a[], int b[], int r[]) {
    if (a[0] > b[0]) {
        if ((a[0] >= r[0]) && (b[0] <= r[0]))
            return 1;
    } else if ((a[0] <= r[0]) && (b[0] >= r[0]))
        return 1;

    return 0;
}

int decide(int a[], int b[], int c[], int d[], int r[]) {
   
    if (a[0] == b[0]) { 
        if (a[1] > b[1])
            if ((a[1] >= r[1]) && (b[1] <= r[1]))
                return decide_x(a, d, r);
        else if ((a[1] <= r[1]) && (b[1] >= r[1]))
            return decide_x(a, d, r);
    } else if (a[1] > d[1]) {
        if ((a[1] >= r[1]) && (d[1] <= r[1]))
            return decide_x(a, b, r);
    } else if ((a[1] <= r[1]) && (d[1] >= r[1])) 
        return decide_x(a, b, r);

    return 0;
}

int main() {
    
    int tests;
    int a[2], b[2], c[2], d[2], r[2];

    scanf("%d", &tests);

    for (int i = 0; i < tests; i++) {

        scanf("%d %d %d %d %d %d %d %d %d %d",
            &a[0], &a[1], &b[0], &b[1], &c[0], &c[1],
            &d[0], &d[1], &r[0], &r[1]);

        printf("%d\n", decide(a, b, c, d, r));
    }

}

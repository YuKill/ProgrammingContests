#include <stdlib.h>
#include <stdio.h>
#include <cstring>

int do_for_all(char *result, int r, int ws, int z, int offset) {
    if ((ws > 2) && (offset % 2 == 0)) {
        result[r++] = '$';
        if (ws > 255) {
            result[r++] = char(255);
            ws -= 255;
            result[r++] = '$';
        }
        result[r++] = char(ws);
    } else if ((z > 2) && (offset % 3 == 0)) {
        result[r++] = '#';
        if (z > 255) {
            result[r++] = char(255);
            z -= 255;
            result[r++] = '#';
        }
        result[r++] = char(z);
    } else if ((ws > 0) && (offset % 2 == 0)) {
        for (int j = 0; j < ws; j++)
            result[r++] = ' ';
    } else if ((z > 0) && (offset % 3 == 0)) {
        for (int j = 0; j < z; j++)
            result[r++] = '0';
    }
    return r;
}

char *process(char buf[]) {
    int l = strlen(buf), ws = 0, z = 0, r = 0;
    char *result = new char(l);

    for (int i = 0; i <= l; i++) {
        if ((i != l) && (buf[i] == ' ')) {
            ws++;
            r = do_for_all(result, r, ws, z, 3);
            z = 0;
        } else if ((i != l) && (buf[i] == '0')) {
            z++;
            r = do_for_all(result, r, ws, z, 2);
            ws = 0;
        } else {
            r = do_for_all(result, r, ws, z, 6);
            z = 0;
            ws = 0;
            result[r++] = buf[i];
        }

    }

    result[r] = '\0';
    return result;
}

int main() {

    int tests;
    scanf("%d", &tests);

    getchar();
    for (int i = 0; i < tests; i++) {
        char buf[2001], c;
        int count = 0;
        while ((c = getchar()) != '\n')
            buf[count++] = c;
        buf[count] = '\0';

        printf("%s\n", process(buf));
    }
}

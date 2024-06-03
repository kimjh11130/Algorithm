#include <stdio.h>

char arr[65][65];

int chk(int n, int x, int y) {
    int z = 0, o = 0;
    if(n == 1) return arr[x][y] == 49;
    for (int i = x; i < x + n / 2; i++) {
        for (int j = y; j < y + n / 2; j++) {
            arr[i][j] == 48 ? z++ : o++;
        }
    }
    if (z && !o) return 0;
    else return z ? 2 : 1;
}

void con(int n, int x, int y) {
    int z = 0, o = 0, res[4], d[2] = {0, n / 2};
    for (int i = 0; i < 4; i++) {
        res[i] = chk(n, x + d[i / 2], y + d[i % 2]);
        if (res[i] == 1) o++;
        if (res[i] == 0) z++;
    }
    if (z == 4) printf("0");
    else if (o == 4) printf("1");
    else {
        printf("(");
        for (int i = 0; i < 4; i++) {
            res[i] == 2 ? con(n / 2, x + d[i / 2], y + d[i % 2]) : printf("%d", res[i]);
        }
        printf(")");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", arr[i]);
    con(n, 0, 0);
}
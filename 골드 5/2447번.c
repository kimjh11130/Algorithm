#include <stdio.h>

short arr[6561][6561];

void star(int n, int i, int x, int y) {
    if (i != 5) {
        if (n == 1) arr[x][y] = 1;
        else {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    star(n / 3, j * 3 + k + 1, x + n / 3 * j, y + n / 3 * k);
                }
            }
        }
    } else {
        for (int j = x; j < x + n / 3; j++) {
            for (int k = y; k < y + n / 3; k++) {
                arr[x][y] = 0;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    star(n, 1, 0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", arr[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
}
#include <stdio.h>

int main() {
    int n, z, arr[1000][1000] = {0};
    scanf("%d\n%d", &n, &z);
    int num = n * n, a = 0, b = n, c = 0, r = n - 1, f = 1, x, y;
    while (1) {
        if (num == 0)break;
        switch (f % 4) {
            case 1:
                for (int i = a; i < b; i++) arr[i][c] = num--;
                break;
            case 2:
                for (int i = a + 1; i < b; i++) arr[r][i] = num--;
                break;
            case 3:
                for (int i = b - 2; i >= a; i--) arr[i][r] = num--;
                a++, r--;
                break;
            case 0:
                for (int i = b - 2; i >= a; i--) arr[c][i] = num--;
                c++, b--;
                break;
            default:
                break;
        }
        f++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
            if (arr[i][j] == z) x = i + 1, y = j + 1;
        }
        printf("\n");
    }
    printf("%d %d", x, y);
}
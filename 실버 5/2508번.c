#include <stdio.h>

int main(void) {
    int t;
    scanf("%d", &t);
    for (int a = 0; a < t; a++) {
        int r, c, cnt = 0;
        char arr[401][401] = {0};
        scanf("%d %d", &r, &c);
        for (int i = 0; i < r; i++) scanf("%s", arr[i]);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c - 2; j++) {
                if (arr[i][j] == '>' && arr[i][j + 1] == 'o' && arr[i][j + 2] == '<') cnt++;
            }
        }
        for (int i = 0; i < r - 2; i++) {
            for (int j = 0; j < c; j++) {
                if (arr[i][j] == 'v' && arr[i + 1][j] == 'o' && arr[i + 2][j] == '^') cnt++;
            }
        }
        printf("%d\n", cnt);
    }
}
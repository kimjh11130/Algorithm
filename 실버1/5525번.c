#include <stdio.h>

int n, m, j, cnt, b;
char str[1000001];

int check(int i) {
    char check[2] = {'I', 'O'};
    for (j = 0; j < m; j++) {
        if (check[j % 2] != str[i + j]) break;
    }
    return j > 0 ? j : 1;
}

int main(void) {
    scanf("%d\n%d\n%s", &n, &m, str);
    for (int i = 0; i < m;) {
        b = check(i);
        i += b, b += b % 2 ? 0 : -1;
        cnt += b >= 2 * n + 1 ? (b - 2 * n - 1) / 2 + 1 : 0;
    }
    printf("%d", cnt);
}
#include <stdio.h>

int main(void) {
    int n, m, cnt1, cnt2, result = 1000000;
    char arr[50][50];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            cnt1 = 0, cnt2 = 0;
            for (int k = i; k < i + 8; k++) {
                for (int l = j; l < j + 8; l++) {
                    if ((k + l) % 2 ? arr[k][l] == 'W' : arr[k][l] == 'B') {
                        cnt1++;
                    }
                    if ((k + l) % 2 ? arr[k][l] == 'B' : arr[k][l] == 'W') {
                        cnt2++;
                    }
                }
            }
            cnt1 = cnt1 > cnt2 ? cnt2 : cnt1;
            result = cnt1 > result ? result : cnt1;
        }
    }
    printf("%d", result);
}
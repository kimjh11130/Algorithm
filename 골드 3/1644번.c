#include <stdio.h>

int n, sosu[283147], idx, f, r, cnt, tmp;
char arr[4000001];

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        if (!arr[i]) {
            sosu[idx++] = i;
            for (int j = i * 2; j <= n; j += i) {
                arr[j] = 1;
            }
        }
    }
    while (f <= r && r <= idx) {
        if (tmp == n) cnt++, tmp += sosu[r++];
        else if (tmp > n)tmp -= sosu[f++];
        else tmp += sosu[r++];
    }
    printf("%d", cnt);
}
#include <stdio.h>

int main() {
    int n, arr[1000001] = {0}, mod = 1e9;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) arr[i] = i / 2 + 1;
    for (int i = 4; i <= n; i *= 2) {
        for (int j = i; j <= n; j++) {
            arr[j] = (arr[j] + arr[j - i]) % mod;
        }
    }
    printf("%d", arr[n]);

}

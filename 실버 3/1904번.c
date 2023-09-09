#include <stdio.h>

int main() {
    int n, arr[1000001] = {0, 1, 2};
    scanf("%d", &n);
    for (int i = 3; i <= n; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
    }
    printf("%d", arr[n]);
}
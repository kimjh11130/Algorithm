#include <stdio.h>

int main() {
    int n, k, arr[100001] = {0}, a = 0, b = 0;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < k; i++) b += arr[i];
    for (int i = k; i <= n; i++) {
        b -= arr[i - k], b += arr[i];
        a = i == k ? b : a > b ? a : b;
    }
    printf("%d ", a);
}
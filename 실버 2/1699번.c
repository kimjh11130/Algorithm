#include <stdio.h>

int min(int a, int b) {
    return !a || a > b ? b : a;
}

int main() {
    int n, arr[100001] = {0};
    scanf("%d", &n);
    for (int i = 1; i * i <= n; i++) {
        for (int j = i*i; j <= n; j++) {
            arr[j] = min(arr[j], arr[j - i*i] + 1);
        }
    }
    printf("%d", arr[n]);
}
#include <stdio.h>

int main() {
    int n, arr[41] = {1, 1};
    scanf("%d", &n);
    for (int i = 2; i < n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    printf("%d %d", arr[n - 1], n - 2);
}
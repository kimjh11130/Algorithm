#include <stdio.h>
int main() {
    int n, a, arr[12] = {1, 2, 4};
    scanf("%d", &n);
    for (int i = 3; i <= 11; i++) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        printf("%d\n", arr[a-1]);
    }
}
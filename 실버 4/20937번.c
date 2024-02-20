#include <stdio.h>

int main(void) {
    int a, n, max = 0, arr[50001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (++arr[a] > max) max = arr[a];
    }
    printf("%d", max);
}
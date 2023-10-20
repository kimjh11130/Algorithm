#include <stdio.h>

int main(void) {
    int n, m, arr[20000002] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        arr[m + 10000000]++;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        printf("%d ", arr[m + 10000000]);
    }
}

#include <stdio.h>

int main(void) {
    int a, k, arr[1000001] = {0};
    scanf("%d %d", &a, &k);
    for (int i = a; i <= k; i++) {
        if (i % 2 == 0 && arr[i / 2] != 0 && arr[i - 1] >= arr[i / 2]) {
            arr[i] = arr[i / 2] + 1;
        } else {
            arr[i] = arr[i - 1] + 1;
        }
    }
    printf("%d", arr[k] - 1);
}
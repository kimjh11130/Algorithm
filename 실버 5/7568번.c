#include <stdio.h>

int main(void) {
    int n, arr[51] = {0}, xs[51] = {0}, ys[51] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &xs[i], &ys[i]), arr[i] = 1;
        for (int j = 0; j < i; j++) {
            if (xs[i] > xs[j] && ys[i] > ys[j]) arr[j]++;
            else if (xs[i] < xs[j] && ys[i] < ys[j]) arr[i]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
}
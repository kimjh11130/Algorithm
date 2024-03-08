#include <stdio.h>

int n, arr[100001][2], a, b, min, cnt;

int abs(int num) { return num > 0 ? num : -num; }

int stepUp(int i, int step) {
    return abs(arr[i - step][0] - arr[i][0]) + abs(arr[i - step][1] - arr[i][1]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", &arr[i][0], &arr[i][1]);
    for (int i = 1; i < n; i++) {
        a = stepUp(i, 1) + stepUp(i + 1, 1);
        b = stepUp(i + 1, 2);
        if (b - a < min && i != n) min = b - a;
        cnt += stepUp(i, 1);
    }
    printf("%d", cnt + min);
}
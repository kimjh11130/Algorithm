#include <stdio.h>

int main() {
    int n, arr[500001], stack[500001][2], t = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    stack[t][0] = arr[0], stack[t][1] = 0, arr[0] = 0;
    for (int i = 1; i < n; i++) {
        while (t >= 0 && stack[t][0] < arr[i]) --t;
        stack[++t][0] = arr[i], stack[t][1] = i, arr[i] = t > 0 ? stack[t - 1][1] + 1 : 0;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

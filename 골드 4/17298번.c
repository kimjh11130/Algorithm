#include <stdio.h>

int main() {
    int n, arr[1000001], stack[1000001][2], t = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    stack[t][0] = arr[0], stack[t][1] = 0;
    for (int i = 1; i < n; i++) {
        while (stack[t][0] < arr[i] && t + 1) arr[stack[t--][1]] = arr[i];
        stack[++t][0] = arr[i], stack[t][1] = i;
    }
    for (int i = 0; i <= t; i++) arr[stack[i][1]] = -1;
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
}
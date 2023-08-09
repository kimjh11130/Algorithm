#include <stdio.h>

int min(int a, int b) { return a > b ? b : a; }

int main(void) {
    int n, arr[100001] = {0, 1, 1, 2, 2, 1, 2, 1};
    scanf("%d", &n);
    for (int i = 8; i <= n; i++) arr[i] += min(min(arr[i - 1], arr[i - 2]), min(arr[i - 5], arr[i - 7])) + 1;
    printf("%d", arr[n]);
}
#include <stdio.h>

int main(void) {
    int n, s, arr[100002] = {0}, f = 0, l = 0, a = 100002;
    scanf("%d %d", &n, &s);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        arr[i] += arr[i - 1];
    }
    while (f <= n) {
        if (arr[f] - arr[l] >= s)a = a > f - l ? f - l : a;
        if (arr[f] - arr[l] >= s) l++;
        else f++;
    }
    printf("%d", a == 100002 ? 0 : a);
}
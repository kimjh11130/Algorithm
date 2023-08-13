#include <stdio.h>

int main(void) {
    int n, a, f, l;
    long long int arr[100001] = {0};
    scanf("%d %d", &n, &a);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &arr[i]);
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i < a; i++) {
        scanf("%d %d", &f, &l);
        printf("%lld\n", arr[l] - arr[f - 1]);
    }
}
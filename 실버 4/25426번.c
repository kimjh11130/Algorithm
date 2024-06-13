#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, arr[100001] = {0}, b;
    ll res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i], &b), res += b;
    }
    qsort(arr, n, 4, comp);
    for (ll i = 0; i < n; i++) {
        res += (ll)arr[i] * (i + 1);
    }
    printf("%lld", res);
}
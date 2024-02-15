#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

ll max(ll a, ll b) { return a > b ? a : b; }

int comp(const void *a, const void *b) {
    return *(ll *) a - *(ll *) b >= 0 ? (*(ll *) a - *(ll *) b == 0 ? 0 : 1) : -1;
}


int main(void) {
    ll a = 0, b, n, arr[10001], m = 0;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    qsort(arr, n, 8, comp);
    if (n % 2) b = n - 2;
    else b = n - 1;

    while (a <= b) {
        m = max(m, arr[a++] + arr[b--]);
    }
    printf("%lld", n % 2 ? max(m, arr[n - 1]) : m);
}

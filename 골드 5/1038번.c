#include <stdio.h>

typedef long long int ll;

int main() {
    int x, r = -1, f = 0, cnt = 1;
    ll que[1030] = {0};
    scanf("%d", &x);
    if (!x) {
        printf("0");
        return 0;
    }
    for (int i = 0; i < 10; i++) que[++r] = i;
    while (f < r) {
        ll n = que[++f];
        if (cnt++ == x) {
            printf("%lld", n);
            return 0;
        }
        for (int i = 0; i < n % 10; i++) que[++r] = n * 10 + i;
    }
    printf("-1");
}
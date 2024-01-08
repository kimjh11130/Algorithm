#include <stdio.h>

int main(void) {
    int n, q, arr[1001] = {0};
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < q; i++) {
        int a, b, c, d, e;
        long long int f = 0, g = 0;
        scanf("%d", &e);
        if (e - 1) {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            for (int j = a; j <= b; j++) f += arr[j];
            for (int j = c; j <= d; j++) g += arr[j];
            printf("%lld\n", f- g);
        } else {
            scanf("%d %d", &a,&b);
            for (int j = a; j <= b; j++) f += arr[j];
            printf("%lld\n", f);
            f = arr[b];
            arr[b] = arr[a];
            arr[a] = f;
        }
    }
}

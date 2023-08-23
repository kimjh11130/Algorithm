#include <stdio.h>

int main(void) {
    int n, m, cu, pr = 0, arr[41] = {1, 1, 2}, g = 1;
    scanf("%d\n%d", &n, &m);
    for (int i = 3; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &cu);
        g *= arr[cu - pr - 1];
        pr = cu;
    }
    printf("%d", g * arr[n - pr]);
}

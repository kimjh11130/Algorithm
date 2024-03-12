#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, c[21], m, v[10002] = {1};
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &c[i]);
        scanf("%d", &m);
        for (int i = 0; i < n; i++) {
            for (int j = c[i]; j <= m; j++) {
                v[j] += v[j - c[i]];
            }
        }
        printf("%d\n", v[m]);
    }
}
#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        int cnt = 0, a[20001] = {0}, b[20001] = {0}, r = 0;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < m; i++) scanf("%d", &b[i]);
        qsort(a, n, 4, comp), qsort(b, m, 4, comp);
        for (int i = 0; i < n; i++) {
            while (a[i] > b[r] && r < m){
                cnt += n - i, r++;
            }
        }
        printf("%d\n", cnt);
    }
}
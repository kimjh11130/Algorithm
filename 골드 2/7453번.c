#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, o[4001][2], t[4001][2], a[16001], b[16001], r, l, idx = 0;
    long long int cnt = 0, curA = 1, curB = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &o[i][0], &t[i][0], &o[i][1], &t[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[idx] = o[i][0] + t[j][0], b[idx++] = o[i][1] + t[j][1];
        }
    }
    qsort(a, idx, 4, comp), qsort(b, idx, 4, comp), l = 0, r = idx - 1;
    while (l < idx && r >= 0) {
        while (l < idx - 1 && a[l] == a[l + 1]) curA++, l++;
        while (r && b[r] == b[r - 1]) curB++, r--;
        if (a[l] + b[r] == 0) cnt += curA * curB;
        if (a[l] + b[r] < 0) curA = 1, l++;
        else curB = 1, r--;
    }
    printf("%lld", cnt);
}

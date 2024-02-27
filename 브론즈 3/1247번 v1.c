#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

int n;
ll arr[100001] = {0};

int comp(const void *a, const void *b) {
    return *(ll *) a > *(ll *) b ? -1 : *(ll *) a == *(ll *) b ? 0 : 1;
}

char solve() {
    ll res[50] = {0}, idx, max = 0;
    for (int i = 0; i < n; i++) {
        idx = 0;
        while (arr[i]) {
            res[idx] += arr[i] % 10;
            for (ll j = idx; res[j] > 9;) res[j] -= 10, res[++j] += 1;
            for (ll j = idx; res[j] < 0;) {
                if (j > 40 && res[j] == -1) return '-';
                res[j] += 10, res[++j] -= 1;
            }
            arr[i] /= 10, idx++;
            if (idx > max) max = idx;
        }
    }
    for (ll i = max + 5; i >= 0; i--) {
        if (res[i] > 0) return '+';
    }
    return '0';
}

int main() {
    for (int i = 0; i < 3; i++) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%lld", &arr[j]);
        }
        qsort(arr, n, sizeof(ll), comp);
        printf("%c\n", solve());
    }
}
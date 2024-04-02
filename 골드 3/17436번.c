#include <stdio.h>

typedef long long int ll;

int m, arr[11];
ll n, cnt;

void back(int idx, int max, ll cur, ll di) {
    if (idx != max) {
        for (ll i = cur; i < m; i++) {
            if (n / arr[i] >= di)back(idx + 1, max, i + 1, di * arr[i]);
        }
    } else {
        cur = n / di;
        cnt += max % 2 ? cur : -cur;
    }
}

int main() {
    scanf("%d %lld", &m, &n);
    for (int i = 0; i < m; i++) scanf("%d", &arr[i]);
    for (int i = 1; i <= m; i++) back(0, i, 0, 1);
    printf("%lld", cnt);
}


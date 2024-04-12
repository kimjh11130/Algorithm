#include <stdio.h>

typedef long long int ll;

int n, l, r, val, tmp, cnt, res, arr[20];
ll next;

ll uclid(ll a, ll b) { return a % b ? uclid(b, a % b) : b; }

void back(int idx, int cur, ll di) {
    val = r / di - (l - 1) / di;
    if (idx)res += idx % 2 ? val : -val;
    if (idx == cnt) return;
    for (int i = cur; i < cnt; i++) {
        next = di / uclid(di, arr[i]) * arr[i];
        if (r >= next)back(idx + 1, i + 1, next);
    }
}

int main() {
    scanf("%d %d %d", &n, &l, &r);
    for (int i = 0, j = 0; i < n; i++, j = 0) {
        scanf("%d", &tmp);
        while (j < cnt && tmp % arr[j]) j++;
        if (j == cnt) arr[cnt++] = tmp;
    }
    back(0, 0, 1);
    printf("%d", res);
}

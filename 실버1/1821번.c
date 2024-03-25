#include <stdio.h>

int n, f, a = 1, b = 1, flag;
int vis[11], res[11], cb[12], fac[11] = {1};

void back(int s, int idx) {
    if (idx == n && s >= f && !flag) {
        if (s == f) {
            flag = 1;
            for (int i = 0; i < n; i++) {
                printf("%d ", res[i]);
            }
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                vis[i] = 1, res[idx] = i;
                back(s + i * cb[idx], idx + 1);
                vis[i] = 0;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &f);
    while (b <= 10)a *= b, fac[b++] = a;
    for (int i = 0; i < n; i++) {
        cb[i] = fac[n - 1] / fac[i] / fac[n - i - 1];
    }
    back(0, 0);
}
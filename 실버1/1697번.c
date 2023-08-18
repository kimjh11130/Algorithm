#include <stdio.h>

int main(void) {
    int n, k, arr[200010] = {0}, que[200010][2] = {0}, r = -1, f = -1;
    scanf("%d %d", &n, &k);
    if (n >= k) {
        printf("%d", n - k);
        return 0;
    }
    que[++r][0] = n, que[r][1] = 1, arr[n] = 1;
    while (r > f) {
        int a = que[++f][0], s[3] = {a + 1, a - 1, a * 2};
        for (int i = 0; i < 3; i++) {
            if (k == s[i]) {
                printf("%d", que[f][1]);
                return 0;
            } else if (s[i] < 200000 && !arr[s[i]]) {
                que[++r][0] = s[i], que[r][1] = que[f][1] + 1;
                arr[s[i]] = 1;
            }
        }
    }
}
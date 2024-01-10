#include <stdio.h>

int n, m, i, arr[9], vis[9];

void back() {
    if (m == i) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    } else {
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && arr[i] < j) {
                vis[j] = 1, arr[++i] = j;
                back();
                vis[j] = 0, i--;
            }
        }
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    back();
}
#include <stdio.h>

int n, m, i, arr[9];

void back() {
    if (m == i) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    } else {
        for (int j = 1; j <= n; j++) {
            arr[++i] = j;
            back();
            i--;
        }
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    back();
}
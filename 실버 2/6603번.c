#include <stdio.h>

int k, arr[13], res[6];

int back(int idx, int cur) {
    if (idx == 6) {
        for (int i = 0; i < 6; i++) printf("%d ", res[i]);
        printf("\n");
    } else {
        for (int i = cur; i < k - 5 + idx; i++) {
            res[idx] = arr[i], back(idx + 1, i + 1);
        }
    }
}

int main() {
    while (1) {
        scanf("%d", &k);
        if (!k) break;
        for (int i = 0; i < k; i++) scanf("%d", &arr[i]);
        back(0, 0);
        printf("\n");
    }
}
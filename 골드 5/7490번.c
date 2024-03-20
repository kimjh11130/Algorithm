#include <stdio.h>

char res[10];

void back(int idx, int minus, int flus, int sign, int cur, int n) {
    if (idx == n) {
        if (sign) flus += cur;
        else minus += cur;
        if (minus == flus) {
            for (int i = 1; i < n; i++) printf("%d%c", i, res[i]);
            printf("%d\n", n);
        }
    } else {
        res[idx] = 32, back(idx + 1, minus, flus, sign, cur * 10 + idx + 1, n);
        if (sign) flus += cur;
        else minus += cur;
        res[idx] = 43, back(idx + 1, minus, flus, 1, idx + 1, n);
        res[idx] = 45, back(idx + 1, minus, flus, 0, idx + 1, n);
    }
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        back(1, 0, 0, 1, 1, n);
        printf("\n");
    }
}

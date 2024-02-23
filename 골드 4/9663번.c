#include <stdio.h>

int n, all;
short sero[15], left[30], right[30];

void back(int i) {
    if (i == n) all++;
    else {
        for (int j = 0; j < n; j++) {
            if (!sero[j] && !left[i + j] && !right[j - i + 14]) {
                sero[j] = 1, left[i + j] = 1, right[j - i + 14] = 1;
                back(i + 1);
                sero[j] = 0, left[i + j] = 0, right[j - i + 14] = 0;
            }
        }
    }
}

int main(void) {
    scanf("%d", &n);
    back(0);
    printf("%d", all);
}
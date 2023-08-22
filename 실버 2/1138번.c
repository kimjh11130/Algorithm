#include <stdio.h>

int main(void) {
    int n, arr[10] = {0}, re[10] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        int l = 0;
        while (arr[i] >= l) {
            if (re[l]) arr[i]++, l++;
            else l++;
        }
        re[l - 1] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", re[i]);
    }
}
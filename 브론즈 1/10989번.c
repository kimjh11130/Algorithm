#include <stdio.h>

int main(void) {
    int n, arr[10001] = {0}, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        arr[m]++;
    }
    for (int i = 1; i < 10001; i++) {
        for (int j = 0; j < arr[i]; j++) {
            printf("%d\n", i);
        }
    }
}
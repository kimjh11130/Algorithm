#include <stdio.h>

int main(void) {
    int all[1000001] = {0}, i, cnt = 0, n;
    for (i = 1; cnt != 1000000; i++) {
        int arr[10] = {0}, a = cnt, b = i;
        while (1) {
            if (b == 0) {
                all[cnt] = i;
                break;
            } else if (arr[b % 10] == 1) {
                cnt = a;
                break;
            } else arr[b % 10] = 1, b /= 10, cnt = a + 1;
        }
    }
    while (1) {
        scanf("%d", &n);
        if (n == 0) return 0;
        printf("%d\n", all[n]);
    }
}

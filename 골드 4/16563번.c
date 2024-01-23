#include <stdio.h>

int main(void) {
    int t, n, arr[2240] = {0}, s = 0, sosu[350];;
    for (int i = 2; i < 2240; i++) {
        if (!arr[i]) {
            sosu[s++] = i;
            for (int j = 2 * i; j < 2240; j += i) {
                arr[j] = 1;
            }
        }
    }
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        int j = 0;
        while (n - 1) {
            int a = sosu[j];
            if (n % a == 0) printf("%d ", a), n /= a;
            else if (a * a > n) printf("%d", n), n = 1;
            else j++;
        }
        printf("\n");
    }
}
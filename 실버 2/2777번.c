#include <stdio.h>

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int a = 0, j = 9;
        scanf("%d", &n);
        if(n==1) {
            printf("1\n");
            continue;
        }
        while (j > 1) {
            if (n % j == 0) a++, n /= j;
            else j--;
        }
        printf("%d\n",n == 1 ? a : -1);
    }
}
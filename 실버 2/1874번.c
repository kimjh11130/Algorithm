#include <stdio.h>

int main(void) {
    int a, n, stack[100001] = {0}, top = 0, r = -1;
    char result[1000001] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        stack[i] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a > top) {
            while (top <= a) {
                if (stack[top++] != 0) result[++r] = '+';
            }
            stack[--top] = 0, result[++r] = '-';
        } else {
            for (top -= 1; top > a; top--) {
                if (stack[top] != 0) {
                    printf("NO");
                    return 0;
                }
            }
            stack[top] = 0, result[++r] = '-';
        }
    }
    for (int i = 0; i <= r; i++) {
        printf("%c\n", result[i]);
    }
}
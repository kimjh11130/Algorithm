#include <stdio.h>
#include <string.h>

int main(void) {
    int n, stack[10001] = {0}, a = -1;
    char arr[5] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr);
        if (strcmp(arr, "push") == 0) scanf("%d", &stack[++a]);
        else if (strcmp(arr, "pop") == 0) {
            if (a == -1) printf("-1\n");
            else printf("%d\n", stack[a--]);
        } else if (strcmp(arr, "size") == 0) printf("%d\n", a + 1);
        else if (strcmp(arr, "empty") == 0) printf("%d\n", a == -1 ? 1 : 0);
        else if (strcmp(arr, "top") == 0) {
            if (a == -1) printf("-1\n");
            else printf("%d\n", stack[a]);
        }
    }
}
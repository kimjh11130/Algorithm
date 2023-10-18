#include <stdio.h>

int main(void) {
    int n, que[10001] = {0}, f = -1, r = -1;
    char arr[6] = {0}, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr), a = arr[1];
        if (a == 'u') { scanf("%d", &que[++r]); }
        else if (a == 'o') {
            if (f == r) printf("-1\n");
            else printf("%d\n", que[++f]);
        } else if (a == 'i') {
            printf("%d\n", r - f);
        } else if (a == 'm') {
            printf("%d\n", r == f ? 1 : 0);
        } else if (a == 'r') {
            if (r == f || r == -1) printf("-1\n");
            else printf("%d\n", que[f + 1]);
        } else if (a == 'a') {
            if (r == f || r == -1)printf("-1\n");
            else printf("%d\n", que[r]);
        }
    }
}

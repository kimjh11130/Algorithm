#include <stdio.h>
#include <string.h>

int main(void) {
    int n, deque[20010] = {0}, f = 10005, r = 10005;
    char arr[11] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr);
        if (strcmp(arr, "push_front") == 0) {
            scanf("%d", &deque[--f]);
        } else if (strcmp(arr, "push_back") == 0) {
            scanf("%d", &deque[r++]);
        } else if (strcmp(arr, "pop_front") == 0) {
            if (r == f || deque[f] == 0) printf("-1\n");
            else printf("%d\n", deque[f++]), deque[f-1] = 0;
        } else if (strcmp(arr, "pop_back") == 0) {
            if (r == f || deque[r - 1] == 0) printf("-1\n");
            else printf("%d\n", deque[--r]), deque[r] = 0;
        } else if (strcmp(arr, "size") == 0) {
            printf("%d\n", r - f);
        } else if (strcmp(arr, "empty") == 0) {
            printf("%d\n", r == f ? 1 : 0);
        } else if (strcmp(arr, "front") == 0) {
            printf("%d\n", deque[f] == 0 ? -1 : deque[f]);
        } else if (strcmp(arr, "back") == 0) {
            printf("%d\n", deque[r - 1] == 0 ? -1 : deque[r - 1]);
        }
    }
}

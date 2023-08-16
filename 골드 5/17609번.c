#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    char arr[100001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr);
        int f = -1, l = strlen(arr), c = 0, z = 0;
        while (f < l) {
            if (arr[f + 1] == arr[l - 1])++f, --l;
            else if (arr[f + 2] == arr[l - 1])f += 2, --l, c++;
            else c = 2;
            if (c > 1) break;
        }
        f = -1, l = strlen(arr);
        while (f < l) {
            if (arr[f + 1] == arr[l - 1])++f, --l;
            else if (arr[f + 1] == arr[l - 2])++f, l -= 2, z++;
            else z = 2;
            if (z > 1) break;
        }
        printf("%d\n", (c > z ? z : c) > 1 ? 2 : (c > z ? z : c));
    }
}
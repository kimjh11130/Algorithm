#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int main() {
    int n, cnt[27] = {0}, a = 9, res = 0, l, ten;
    char arr[9];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr);
        ten = 1, l = strlen(arr) - 1;
        for (int j = l; j >= 0; j--) {
            cnt[arr[j] - 'A'] += ten, ten *= 10;
        }
    }
    qsort(cnt, 26, 4, comp);
    for (int i = 0; cnt[i]; ++i) res += cnt[i] * a--;
    printf("%d", res);
}
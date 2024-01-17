#include <stdio.h>
#include <stdlib.h>

int l, c, n, vis[16], g;
char arr[16], res[16];

int comp(const void *a, const void *b) {
    return *(char *) a - *(char *) b;
}

void back() {
    if (n == l && g && l - g > 1) {
        for (int i = 1; i <= n; i++) {
            printf("%c", res[i]);
        }
        printf("\n");
    } else {
        for (int i = 0; i < c; i++) {
            if (!vis[i] && res[n] < arr[i]) {
                if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') g++;
                vis[i] = 1, res[++n] = arr[i];
                back();
                vis[i] = 0, n--;
                if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') g--;
            }
        }
    }
}

int main(void) {
    scanf("%d %d", &l, &c);
    for (int i = 0; i < c; i++) {
        scanf(" %1c", &arr[i]);
    }
    qsort(arr, c, 1, comp);
    back();
}
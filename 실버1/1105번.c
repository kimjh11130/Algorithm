#include <stdio.h>
#include <string.h>

int main(void) {
    char l[11] = {0}, r[11] = {0};
    scanf("%s %s", l, r);
    int a = strlen(l) > strlen(r) ? strlen(r) : strlen(l), b = 0;
    if (strlen(l) == strlen(r)) {
        for (int i = 0; i < a; i++) {
            if (l[i] == r[i]) {
                if (l[i] == 56)b++;
            } else break;
        }
    } else b = 0;
    printf("%d", b);
}
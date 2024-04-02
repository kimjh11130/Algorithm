#include <stdio.h>
#include <string.h>

int main() {
    char a[1001], b[1001], tmp[1001] = {0};
    scanf("%s %s", a, b);
    int al = strlen(a) - 1, bl = strlen(b) - 1, flag = 1;
    while (al != bl) {
        if (b[bl] == 'A') b[bl] = 0, bl--;
        else {
            b[bl] = 0, bl--;
            for (int i = 0; i <= bl; i++) tmp[i] = b[bl - i];
            for (int i = 0; i <= bl; i++) b[i] = tmp[i];
        }
    }
    for (int i = 0; i <= bl; i++) {
        if (a[i] != b[i]) {
            flag = 0;
            break;
        }
    }
    printf("%d", flag);
}


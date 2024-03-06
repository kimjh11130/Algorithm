#include <stdio.h>
#include <string.h>

int main() {
    char arr[1000001] = {0}, stack[1000001] = {0}, bomb[37] = {0};
    scanf("%s %s", arr, bomb);
    int arrlen = strlen(arr), bomblen = strlen(bomb), r = 0;
    for (int i = 0; i < arrlen; i++) {
        stack[r++] = arr[i];
        if (r < bomblen) continue;
        int cnt = 1;
        while (cnt != bomblen + 1) {
            if (bomb[bomblen - cnt] != stack[r - cnt]) break;
            cnt++;
        }
        if (cnt == bomblen + 1){
            r -= bomblen;
            for (int j = r; j <= r + bomblen; j++) {
                stack[j] = 0;
            }
        }
    }
    if (r) {
        printf("%s", stack);
    } else printf("FRULA");
}
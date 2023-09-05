#include <stdio.h>
#include <string.h>

int main() {
    char arr[51] = {0};
    scanf("%s", arr);
    int a = 0, b = 0, c = 1, l = strlen(arr);
    for (int i = 0; i < l; i++) {
        if (arr[i] == '+') a += c ? b : -b, b = 0;
        else if (arr[i] == '-') a += c ? b : -b, b = 0, c = 0;
        else b = b * 10 + arr[i] - 48;
    }
    printf("%d", a + (c ? b : -b));
}
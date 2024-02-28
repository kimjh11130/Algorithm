#include <stdio.h>
#include <string.h>

int main() {
    char arr[1000010] = {0};
    scanf("%s", arr);
    int a = 0, b = strlen(arr), two = b % 3 ? b % 3 : 4;
    for (int i = 0; i < b; i++, two /= 2) {
        if (arr[i] == '1') a += two;
        if (i % 3 == (b - 1) % 3) printf("%d", a), a = 0, two = 8;
    }
}
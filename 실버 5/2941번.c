#include <stdio.h>
#include <string.h>

int main() {
    int res = 0, i = 0;
    char a, b, c, arr[104];
    scanf("%s", arr);
    while (i < strlen(arr)) {
        a = arr[i], b = arr[i + 1], c = arr[i + 2];
        if ((a == 'c' && b == '-') || (a == 'd' && b == '-') || (b == 'j' && (a == 'l' || a == 'n')) ||
            (b == '=' && (a == 's' || a == 'z' || a == 'c')))
            i++;
        else if (a == 'd' && b == 'z' && c == '=') i += 2;
        res++, i++;
    }
    printf("%d", res);
}
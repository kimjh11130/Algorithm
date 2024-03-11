#include <stdio.h>

int a, c, i = -1;
int main() {
    char s[100001];
    scanf("%s", s);
    while (s[++i] != '\0') {
        if (s[i] == '(') c++;
        else a += s[i - 1] == '(' ? c - 1 : 1, c--;
    }
    printf("%d", a);
}
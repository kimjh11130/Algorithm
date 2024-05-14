#include <stdio.h>
#include <string.h>

int len;
char ch[28] = {0}, str[60];

void cout(int i) {
    for (int j = 0; j < len; j++) {
        if (j == i) printf("[%c]", str[j]);
        else printf("%c", str[j]);
    }
    printf("\n");
}

int check(int i) {
    if ('a' <= str[i] && str[i] <= 'z' && !ch[str[i] - 'a']) {
        cout(i), ch[str[i] - 'a'] = 1;
        return 1;
    }
    if ('A' <= str[i] && str[i] <= 'Z' && !ch[str[i] - 'A']) {
        cout(i), ch[str[i] - 'A'] = 1;
        return 1;
    }
    return 0;
}

int main() {
    int n,flag, a;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        a = 0, flag = 0;
        gets(str), len = strlen(str);
        for (int j = 0; j < len; j++) {
            if (a) break;
            if (str[j] == ' ') flag = 0;
            else if (!flag) a = check(j), flag = 1;
        }
        for (int j = 0; j < len; j++) {
            if (a) break;
            a = check(j);
        }
        if(!a) cout(len + 1);
    }
}

#include <stdio.h>
#include <string.h>

int main() {
    int t, cnt = 0;
    scanf("%d", &t);
    while (t--) {
        int vis[28] = {0}, f = 0;
        char arr[101];
        scanf("%s", arr);
        for (int i = 1; i < strlen(arr); i++) {
            if (arr[i - 1] != arr[i] && vis[arr[i] -'a']) f = 1;
            else vis[arr[i - 1] - 'a'] = 1;
        }
        if (!f) cnt++;
    }
    printf("%d", cnt);
}
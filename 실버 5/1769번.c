#include <stdio.h>
#include <string.h>

int main(void) {
    int n = 0, cnt = 1;
    char arr[1000001] = {0};
    scanf("%s", arr);
    for (int i = 0; i < strlen(arr); i++) {
        n += arr[i] - 48;
    }
    if(strlen(arr) == 1) cnt = 0;
    while (n >= 10) {
        int tmp = 0;
        while (n > 0) {
            tmp += n % 10;
            n /= 10;
        }
        n = tmp;
        cnt++;
    }
    printf("%d\n", cnt);
    if (n % 3 == 0)printf("YES");
    else printf("NO");
}
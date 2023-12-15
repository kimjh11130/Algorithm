#include <stdio.h>
#include <string.h>

int main(void) {
    char arr[40] = {0}, colon = 1, cnt = 3;
    scanf("%s", arr);
    for (int i = 1; i < strlen(arr); i++) {
        if (arr[i] == ':' && arr[i-1] != ':') colon++;
    }
    for (int i = 1; i < strlen(arr); i++) {
        if (arr[i] == ':') {
            if (arr[i - 1] == ':') {
                for (int j = 1; j <= (8 - colon) * 5; ++j) {
                    printf("%c", j % 5 ? '0' : ':');
                }
            } else {
                for (int j = 1; j < 5; j++) {
                    printf("%c", j > cnt ? arr[i - 5 + j] : '0');
                }
                printf(":");
            }
            cnt = 4;
        } else cnt--;
    }
    for (int j = 1; j < 5; j++) {
        printf("%c", j > cnt ? arr[strlen(arr) - 5 + j] : '0');
    }
}
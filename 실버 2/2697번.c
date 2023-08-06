#include <stdio.h>
#include <string.h>

int main(void) {
    int a, j;
    scanf("%d", &a);
    for (int i = 0; i < a; i++) {
        char arr[81] = {0};
        scanf("%s", arr);
        int length = strlen(arr), b = length;
        for (j = length - 2; j >= 0; j--) {
            if (arr[j + 1] > arr[j]) {
                char tmp = 0;
                while (arr[j] >= tmp){
                    tmp = arr[--b];
                }
                arr[b] = arr[j];
                arr[j] = tmp;
                break;
            }
        }
        if (j == -1) {
            printf("BIGGEST\n");
        } else {
            for (int k = 0; k < length; k++) {
                if (k <= j) printf("%c", arr[k]);
                else printf("%c", arr[length + j - k]);
            }
            printf("\n");
        }
    }
}

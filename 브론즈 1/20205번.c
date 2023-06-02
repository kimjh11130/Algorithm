#include <stdio.h>

int x, y, arr[11][11] = {0};

int main(void){
    scanf("%d %d",&x ,&y);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int total = x * y;
    for (int i = total; i >= 1; i--) {
        for (int j = total; j >= 1; j--) {
            printf("%d ", arr[(total-i)/y][(total-j)/y]);
        }
        printf("\n");
    }
}
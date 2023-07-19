#include <stdio.h>

int main(void) {
    int n, k, b[101][10001] = {0};
    int weight[101] = {0};
    int value[101] = {0};
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &weight[i], &value[i]);
    }
    for (int i = 1; i <= n; i++) {//아이템 별로
        for (int j = 1; j <= k; j++) {//무게로 쭉
            if (weight[i] <= j) {
                if(b[i-1][j] > b[i-1][j-weight[i]] + value[i]){
                    b[i][j] = b[i-1][j];
                } else{
                    b[i][j] = b[i-1][j-weight[i]] + value[i];
                }
            } else {
                b[i][j] = b[i - 1][j];
            }
        }
    }
    printf("%d", b[n][k]);
}

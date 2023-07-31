#include <stdio.h>
#include <string.h>

int main() {
    int dp[1001][1001] = {0}, a, b;
    char one[1001] = {0}, two[1001] = {0};
    scanf("%s", one);
    scanf("%s", two);
    a = strlen(one), b = strlen(two);
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if(one[i-1] == two[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
        }
    }
    printf("%d", dp[a][b]);
}
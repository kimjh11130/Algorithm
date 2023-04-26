#include <stdio.h>

int check(int i, int j){
    int n = i == j ||
    i == 0 && j == 5 ||
    i == 1 && j == 4 ||
    i == 2 && j == 3 ||
    i == 3 && j == 2 ||
    i == 4 && j == 1 ||
    i == 5 && j == 0 ? 0 : 1;
    return n;
}
int main(void){

    long long int result = 0;
    long long int n, twoMax = 100, threeMax = 150, max = 0, min = 50, all = 0;
    int arr[500];
    scanf("%lld", &n);
    for (int i = 0; i < 6; i++) {
        scanf("%lld", &arr[i]);
        max < arr[i] ? max = arr[i] : max;
        min > arr[i] ? min = arr[i] : max;
        all += arr[i];
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if(check(i, j) && twoMax > arr[i] + arr[j] ) {
                twoMax = arr[i] + arr[j];
            };
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if(!check(i, j)) continue;
            for (int k = 0; k < 6; k++) {
                if(check(i, k) && check(j, k) && threeMax > arr[i] + arr[j] + arr[k]){
                    threeMax = arr[i] + arr[j] + arr[k];
                }
            }
        }
    }
    if(n == 1){
        result = all - max;
        printf("%lld", result);
        return 0;
    }
    result = threeMax * 4 + twoMax * (8 * n - 12) + (n - 2) * (5 * n - 6) * min;
    printf("%lld", result);
    return 0;
}
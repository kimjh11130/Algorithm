#include <stdio.h>

int main(void){
    int n, value, cnt = 0, arr[10] = {0};
    scanf("%d %d", &n, &value);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    for (int i = n-1; i >= 0 && n; i--) {
        while( value >= arr[i]){\
            value -= arr[i];
            cnt++;
        }
    }
    printf("%d", cnt);
}
#include <stdio.h>

int main(void) {
    int a;
    long long int arr[91] ={0,1};
    scanf("%d", &a);
    for (int i = 2; i <= a; ++i) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    printf("%lld", arr[a]);
}
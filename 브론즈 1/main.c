#include <stdio.h>

int main() {
    int arr[5], res = 0, a, f = 5;
    while(f--) {
        scanf("%d", &arr[f]);
    }
    while (1) {
        a = 0,f = 5, res++;
        while(f--)
            if (res % arr[f] == 0) a++;
        if (a > 2) break;
    }
    printf("%d", res);
}
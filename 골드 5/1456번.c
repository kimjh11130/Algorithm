#include <stdio.h>

typedef long long int ll;

int arr[10000010] = {1, 1};

int main(void) {
    ll a, b, c, cnt = 0;
    scanf("%lld %lld", &a, &b);
    for (ll i = 2; i * i <= b; i++) {
        if (arr[i] == 0) {
            c = i;
            while (c <= b / i){
                c *= i;
                if(c >= a) cnt++;
            }
            for (ll j = i * 2; j * j <= b; j += i) {
                arr[j] = 1;
            }
        }
    }
    printf("%lld", cnt);
}

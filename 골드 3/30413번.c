#include <stdio.h>

typedef long long int ll;

ll r, n, mod = 1e9 + 7;

ll diqu(ll a, ll b) {
    long long int res = 1;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res % mod;
}

int main(void) {
    scanf("%lld %lld", &r, &n);
    if(r == 1){
        printf("%lld", n % mod);
        return 0;
    }
    printf("%lld", (diqu(r, n) - 1) * diqu(r - 1, mod - 2) % mod);
}
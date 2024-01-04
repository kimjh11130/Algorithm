#include <stdio.h>

typedef long long int ll;

ll n, k, mod = 1e9 + 7, nf = 1, kf, nkf;

ll pow(ll a, ll b) {
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
    scanf("%lld %lld", &n, &k);
    if(n == k || k == 0){
        printf("1");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        nf = nf * i % mod;
        if (i == k) kf = nf;
        if (i == n - k) nkf = nf;
    }
    printf("%lld", nf * pow(kf * nkf % mod, mod - 2) % mod);
}
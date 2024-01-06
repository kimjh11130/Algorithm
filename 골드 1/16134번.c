#include <stdio.h>

typedef long long int ll;

ll r, n, mod = 1e9 + 7, nf = 1, rf = 1, nrf = 1;

ll pow(ll a, ll b) {
    ll res = 1;
    while (b != 0) {
        if (b % 2) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int main(void) {
    scanf("%lld %lld", &n, &r);
    for (int i = 1; i <= n; i++) {
        nf = nf * i % mod;
        if (i == r) rf = nf;
        if (i == n - r) nrf = nf;
    }
    printf("%lld", nf * pow(rf * nrf % mod, mod - 2) % mod);
}
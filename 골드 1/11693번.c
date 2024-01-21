#include <stdio.h>

typedef long long int ll;

int mod = 1e9 + 7;

ll pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b % 2) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int main(void) {
    ll n, m, res = 1, i = 2, j = 0;
    scanf("%lld %lld", &n, &m);
    while (n > 1 || j) {
        if (n % i == 0) n /= i, j++;
        else if (j) {
            res = res * (pow(i, j * m + 1) - 1) % mod;
            res = res * pow(i - 1, mod - 2) % mod;
            j = 0;
        } else if (i * i > n) {
            res = res * (pow(n, m + 1) - 1) % mod;
            res = res * pow(n - 1, mod - 2) % mod;
            break;
        } else i++;
    }
    printf("%lld", res);
}
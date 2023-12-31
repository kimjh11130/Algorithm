#include <stdio.h>

typedef long long int ll;
ll N, A, mod = 1e9 + 7;

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
    scanf("%lld %lld", &N, &A);
    ll r = pow(N, A + 1), res = pow(N - 1, A) * N % mod;
    res = (r - res + mod) * (N - 2) % mod;
    printf("%lld", (r + res) % mod);

}
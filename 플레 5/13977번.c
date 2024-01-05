#include <stdio.h>

typedef long long int ll;

ll c = 1, m, n, k, mod = 1e9 + 7, arr[4000001] = {0};

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
    for (int i = 1; i < 4000001; ++i) {
        c = c * i % mod;
        arr[i] = c;
    }
    scanf("%lld", &m);
    for (int i = 0; i < m; i++) {
        scanf("%lld %lld", &n, &k);
        if(n == k || k == 0){
            printf("1\n");
            continue;
        }
        printf("%lld\n", arr[n] * pow(arr[k] * arr[n-k] % mod, mod -2) % mod);
    }
}
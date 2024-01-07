#include <stdio.h>

typedef long long int ll;

ll uclid(ll a, ll b) {
    ll r = a % b;
    return r ? uclid(b, a % b) : b;
}

int main(void) {
    ll a, d, m, D, M, tmp, cnt = 0;
    scanf("%lld %lld", &d, &m);
    scanf("%lld", &D);
    for (int i = 1; i < d; i++) {
        scanf("%lld", &a);
        tmp = uclid(a, D);
        D = D * a / tmp;
    }
    scanf("%lld", &M);
    for (int i = 1; i < m; i++) {
        scanf("%lld", &a);
        M = uclid(a, M);
    }
    for (int i = 1; i * i <= M; i++) {
        if (M % i == 0) {
            if (i % D == 0) {
                cnt++;
                if (i * i == M) cnt--;
            }
            if (M / i % D == 0) cnt++;
        }
    }
    printf("%lld", cnt);
}

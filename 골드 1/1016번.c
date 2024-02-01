#include <stdio.h>

typedef long long int ll;

int main() {
    ll min, max, cnt = 0, a;
    short arr[1000002] = {0}, prime[1000002] = {0};
    scanf("%lld %lld", &min, &max);
    for (ll i = 2; i * i <= max; i++) {
        if (!arr[i]) {
            a = i * i;
            for (ll j = (min / a + (!(min % a) ? 0 : 1)) * a - min; j <= max - min; j += a) {
                if (!prime[j]) cnt++;
                prime[j] = 1;
            }
            for (ll j = 2 * i; j < 1000002; j += i) {
                arr[j] = 1;
            }
        }
    }
    printf("%lld", max - min - cnt + 1);
}
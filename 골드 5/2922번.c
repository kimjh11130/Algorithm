#include <stdio.h>
#include <string.h>

typedef long long int ll;

ll n, res;
char a, arr[101];

void back(ll idx, ll cnt, ll ja, ll mo, ll isL) {
    if (ja == 3 || mo == 3) return;
    else if (idx == n && isL) res += cnt;
    else {
        a = arr[idx];
        if (a == '_') {
            ll l = 21;
            if (!isL) back(idx + 1, cnt, ja + 1, 0, 1), l = 20;
            back(idx + 1, cnt * 5, 0, mo + 1, isL);
            back(idx + 1, cnt * l, ja + 1, 0, isL);
        } else if (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U') back(idx + 1, cnt, 0, mo + 1, isL);
        else if (a == 'L') back(idx + 1, cnt, ja + 1, 0, 1);
        else back(idx + 1, cnt, ja + 1, 0, isL);
    }
}

int main(void) {
    scanf("%s", arr);
    n = strlen(arr);
    back(0, 1, 0, 0, 0);
    printf("%lld", res);
}

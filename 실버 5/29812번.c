#include <stdio.h>

int min(int a, int b) { return a > b ? b : a; }

int main() {
    int n, d, m, h = 0, y = 0, u = 0, e = 0, cnt = 0, a;
    char str[200001] = {0}, c;
    scanf("%d %s %d %d", &n, str, &d, &m);
    for (int i = 0; i < n; i++) {
        c = str[i];
        if (c == 'H' || c == 'Y' || c == 'U') {
            e += min(cnt * d, m + d), cnt = 0;
            if (c == 'H') h++;
            if (c == 'Y') y++;
            if (c == 'U') u++;
        } else cnt++;
    }
    e += min(cnt * d, m + d);
    a = min(min(h, y), u);

    if (!e) printf("Nalmeok\n");
    else printf("%d\n", e);

    if (!a) printf("I love HanYang University");
    else printf("%d", a);
}
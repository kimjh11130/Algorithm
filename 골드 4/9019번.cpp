#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t, a, b, c;
    cin >> t;
    while (t--) {
        int vis[10001] = {0};
        queue<pair<int, string>> que;
        cin >> a >> b;
        que.emplace(a, "");
        while (!que.empty()) {
            auto [n, str] = que.front();
            que.pop();
            if (n == b) {
                cout << str << "\n";
                break;
            }
            c = n * 2 % 10000;
            if (!vis[c])vis[c] = 1, que.emplace(c, str + "D");
            c = (n + 9999) % 10000;
            if (!vis[c])vis[c] = 1, que.emplace(c, str + "S");
            c = n % 1000 * 10 + n / 1000;
            if (!vis[c])vis[c] = 1, que.emplace(c, str + "L");
            c = n % 10 * 1000 + n / 10;
            if (!vis[c])vis[c] = 1, que.emplace(c, str + "R");
        }
    }
}

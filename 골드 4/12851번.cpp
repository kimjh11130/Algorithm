#include <iostream>
#include <queue>

using namespace std;

int isMin(int a, int b) { return !a || a >= b; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k, cnt = 0, max = 0, vis[140001] = {0};
    queue<pair<int, int>> que;
    cin >> n >> k;
    que.emplace(n, 0), vis[n] = 1;
    while (!que.empty()) {
        auto [x, c] = que.front();
        que.pop();
        if (max && c > max) break;
        if (x == k) max = c, cnt++;
        if (2 * k >= 3 * x && isMin(vis[x * 2], c + 1))vis[x * 2] = c + 1, que.emplace(x * 2, c + 1);
        if (x < k && isMin(vis[x + 1], c + 1))vis[x + 1] = c + 1, que.emplace(x + 1, c + 1);
        if (x > 0 && isMin(vis[x - 1], c + 1))vis[x - 1] = c + 1, que.emplace(x - 1, c + 1);
    }
    cout << max << "\n" << cnt;
}

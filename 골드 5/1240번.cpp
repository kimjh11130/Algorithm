#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, fr, to, va;
    cin >> n >> m;
    vector<vector<pair<int, int>>> tree(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> fr >> to >> va;
        tree[fr].emplace_back(to, va);
        tree[to].emplace_back(fr, va);
    }
    while (m--) {
        cin >> fr >> to;
        vector<bool> vis(n + 1, false);
        queue <pair<int, int>> que;
        que.emplace(fr, 0);
        while (true) {
            auto [x, d] = que.front();
            que.pop();
            if (x == to) {
                cout << d << "\n";
                break;
            }
            for (auto [a, b]: tree[x]) {
                if (!vis[a]) vis[a] = true, que.emplace(a, d + b);
            }
        }
    }
}

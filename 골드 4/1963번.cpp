#include <iostream>
#include <utility>
#include <queue>

using namespace std;

bool sosu[10000] = {false};

void di(int arr[4], int n) { arr[0] = n / 1000, arr[1] = n / 100 % 10, arr[2] = n / 10 % 10, arr[3] = n % 10; }

int pl(int *n) { return n[0] * 1000 + n[1] * 100 + n[2] * 10 + n[3]; }

int bfs(int a, int b) {
    int tmp[4], g;
    bool vis[10000] = {false};
    queue<pair<int, int>> que;
    que.emplace(a, 0), vis[a] = true;
    while (!que.empty()) {
        auto [n, c] = que.front();
        que.pop();
        if (n == b) return c;
        for (int i = 0; i < 4; i++) {
            di(tmp, n);
            for (int j = 0; j < 10; j++) {
                if (!i && !j) continue;
                tmp[i] = j, g = pl(tmp);
                if (!sosu[g] && !vis[g])vis[g] = true, que.emplace(g, c + 1);
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t, a, b;
    for (int i = 2; i < 10000; i++) {
        if (!sosu[i]) {
            for (int j = i * 2; j < 10000; j += i) sosu[j] = true;
        }
    }
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << bfs(a, b) << "\n";
    }
}
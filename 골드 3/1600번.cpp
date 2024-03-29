#include <iostream>
#include <queue>

using namespace std;

typedef struct element {
    int x, y, z, c;
} element;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k, d[] = {0, -1, 0, 1}, chx[] = {-2, -1, 1, 2, 2, 1, -1, -2}, chy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    char arr[201][201], vis[201][201][31] = {0};
    queue<element> que;
    cin >> k >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    que.push({0, 0, 0, 0});
    while (!que.empty()) {
        auto [x, y, z, c] = que.front();
        if (x == n - 1 && y == m - 1) {
            cout << c;
            return 0;
        }
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[3 - i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] == 48 && !vis[nx][ny][z]) {
                que.push({nx, ny, z, c + 1}), vis[nx][ny][z] = 1;
            }
        }
        for (int i = 0; i < 8; i++) {
            int nx = x + chx[i], ny = y + chy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] == 48 && z < k && !vis[nx][ny][z + 1]) {
                que.push({nx, ny, z + 1, c + 1}), vis[nx][ny][z + 1] = 1;
            }
        }
    }
    cout << -1;
}
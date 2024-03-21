#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, vis[51][51], d[] = {0, 1, 0, -1};
    char arr[51][51];
    queue<pair<int, int>> que;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vis[i][j] = 9999999;
        }
    }
    que.emplace(0, 0), vis[0][0] = 0;
    while (!que.empty()) {
        auto [x, y] = que.front();
        int c = vis[x][y];
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[3 - i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                if (arr[nx][ny]==49  && vis[nx][ny] > c) {
                    que.emplace(nx, ny), vis[nx][ny] = c;
                } else if(arr[nx][ny]==48 && vis[nx][ny] > c + 1){
                    que.emplace(nx, ny), vis[nx][ny] = c + 1;
                }
            }
        }
    }
    cout << vis[n-1][n-1];
}
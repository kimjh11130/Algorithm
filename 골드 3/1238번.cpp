#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dijk(int n, vector<int> &dist, vector<pair<int, int>> graph[1001]) {
    priority_queue<pair<int, int>> que;
    que.emplace(0, n), dist[n] = 0;
    while (!que.empty()) {
        auto [d, x] = que.top();
        que.pop(), d = -d;
        if (dist[x] < d) continue;
        for (auto [next, ran]: graph[x]) {
            if (dist[next] > ran + d) {
                dist[next] = ran + d, que.emplace(-ran - d, next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, x, fr, to, go, max = 0;
    cin >> n >> m >> x;
    vector<int> dist1(n + 1, 1e9), dist2(n + 1, 1e9);
    vector<pair<int, int>> graph1[n + 1], graph2[n + 1];
    while (m--) {
        cin >> fr >> to >> go;
        graph1[fr].emplace_back(to, go);
        graph2[to].emplace_back(fr, go);
    }
    dijk(x, dist1, graph1), dijk(x, dist2, graph2);
    for (int i = 1; i <= n; i++) {
        max = max > dist1[i] + dist2[i] ? max : dist1[i] + dist2[i];
    }
    cout << max;
}
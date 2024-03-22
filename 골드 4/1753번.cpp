#include <iostream>
#include <queue>
#include <vector>

#define INF 999999999

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int v, e, k, from, to, w;
    cin >> v >> e >> k;
    priority_queue<pair<int, int>> que;
    vector<int> dist(v + 1, INF);
    vector<pair<int, int>> graph[20001];
    for (int i = 0; i < e; i++) {
        cin >> from >> to >> w;
        graph[from].emplace_back(to, w);
    }
    que.emplace(0, k), dist[k] = 0;
    while (!que.empty()) {
        int cur_d = -que.top().first, cur_x = que.top().second;
        que.pop();
        for (pair<int, int> item: graph[cur_x]) {
            int next_x = item.first, next_d = cur_d + item.second;
            if (dist[next_x] > next_d) {
                que.emplace(-next_d, next_x), dist[next_x] = next_d;
            }
        }
    }
    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) cout << "INF" << "\n";
        else cout << dist[i] << "\n";
    }
}
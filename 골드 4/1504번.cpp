#include <iostream>
#include <vector>
#include <queue>

#define MAX 7e8

using namespace std;

void dijk(int f, vector<int> &dist, vector<pair<int, int>> graph[801]) {
    priority_queue<pair<int, int>> que;
    que.emplace(0, f), dist[f] = 0;
    while (!que.empty()) {
        auto [d, cur] = que.top();
        que.pop(), d = -d;
        if (dist[cur] < d) continue;
        for (auto [next, dis]: graph[cur]) {
            if (dist[next] > d + dis) {
                dist[next] = d + dis, que.emplace(-d - dis, next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, e, fr, to, go, a, b, o, t;
    vector<int> distA(801, MAX), distB(801, MAX);
    vector<pair<int, int>> graph[801];
    cin >> n >> e;
    while (e--) {
        cin >> fr >> to >> go;
        graph[fr].emplace_back(to, go);
        graph[to].emplace_back(fr, go);
    }
    cin >> a >> b;
    dijk(a, distA, graph), dijk(b, distB, graph);
    o = distA[1] + distA[b] + distB[n], t = distB[1] + distB[a] + distA[n];
    if (o >= MAX && t >= MAX) cout << -1;
    else cout << (o > t ? t : o);
}
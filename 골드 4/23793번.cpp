#include <iostream>
#include <queue>
#include <vector>

#define INF 2e9

using namespace std;

int n;
vector<pair<int, int>> graph[100001];

int dijk(int a, int b, int c) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>> que;
    que.emplace(0, a), dist[a] = 0;
    while (!que.empty()) {
        auto [d, x] = que.top();
        que.pop(), d = -d;
        if (dist[x] < d) continue;
        for (auto [next, ran]: graph[x]) {
            if (next == b) continue;
            if (dist[next] > d + ran) {
                que.emplace(-d - ran, next), dist[next] = ran + d;
            }
        }
    }
    return dist[c] == INF ? -1 : dist[c];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int e, fr, to, va, a, b, c, one, two;
    cin >> n >> e;
    while (e--) {
        cin >> fr >> to >> va;
        graph[fr].emplace_back(to, va);
    }
    cin >> a >> b >> c;
    one = dijk(a, 0, b), two = dijk(b, 0, c);
    cout << (one == -1 || two == -1 ? -1 : one + two) << ' ' << dijk(a, b, c);
}
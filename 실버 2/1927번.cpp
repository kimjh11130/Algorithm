#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a;
    priority_queue<int> que;
    cin >> n;
    while (n--){
        cin >> a;
        if(a) que.push(-a);
        else if(que.empty()) cout << "0\n";
        else cout << -que.top() << "\n", que.pop();
    }
}
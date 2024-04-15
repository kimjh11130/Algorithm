#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a, flan, llan, b, c, res;
    priority_queue<int> queF;
    priority_queue<int, vector<int>, greater<>> queL;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        queF.push(a);
        if (!queL.empty() && queF.top() > queL.top()) queL.push(queF.top()), queF.pop();
        flan = queF.size(), llan = queL.size(), b = 10001, c = 10001;
        if (flan > llan + 1 && !queF.empty()) queL.push(queF.top()), queF.pop();
        if (llan > flan + 1 && !queL.empty()) queF.push(queL.top()), queL.pop();
        flan = queF.size(), llan = queL.size();
        if (!queF.empty()) b = queF.top();
        if (!queL.empty()) c = queL.top();
        if (flan == llan) res = b > c ? c : b;
        else if (flan > llan) res = b;
        else res = c;
        cout << res << "\n";
    }
}
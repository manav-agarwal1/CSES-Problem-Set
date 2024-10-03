#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<int> inDegree(n+1, 0);
    vector<int> res;
    queue<int> q;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        inDegree[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (inDegree[i]==0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        res.push_back(course);

        for (auto& nhbr: graph[course]) {
            inDegree[nhbr]--;
            if (inDegree[nhbr]==0) {
                q.push(nhbr);
            }
        }
    }
    if (res.size() != (size_t)n) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        for (auto& it: res) {
            cout << it << ' ';
        }
        cout << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<int> parent(n+1, 0);
    parent[1] = -1; // keep this different from the dummy in parent
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr==n) {
            vector<int> res;
            while (curr!=-1) {
                res.push_back(curr);
                curr = parent[curr];
            }
            reverse(res.begin(), res.end());
            cout << res.size() << "\n";
            for (auto& it: res) {
                cout << it << ' ';
            }
            cout << "\n";
            return 0;
        }

        for (int& nhbr: graph[curr]) {
            if (parent[nhbr]==0) {
                parent[nhbr] = curr;
                q.push(nhbr);
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
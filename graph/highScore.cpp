#include <bits/stdc++.h>
using namespace std;
const int64_t neg_inf = LLONG_MIN;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int64_t, int64_t>>> graph(n+1);
    vector<vector<int>> rev_graph(n+1);
    vector<int> vistied(n+1, 0);
    vector<int64_t> res(n+1, neg_inf);
    queue<int> q;
    vector<bool> visited(n+1, false);
    q.push(n);
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        rev_graph[v].push_back(u);
    }

    // init
    res[1] = 0;
    // Bellman-Ford
    // instead of running till m-1 we run m iterations
    // if something changes after mth iteration then there is a postiive cycle and we take the nodes whose weights change
    unordered_set<int> inPosCycle;
    for (int i = 0; i < n; i++) {
        for (int u = 1, v, w; u <= n; u++) {
            if (res[u]==neg_inf) {
                continue;
            }
            for (auto& nhbr: graph[u]) {
                v = nhbr.first;
                w = nhbr.second;
                if (i < n-1) {
                    res[v] = max(res[v], res[u]+w);
                }
                else if (res[v] < res[u]+w){
                    inPosCycle.insert(v);
                }
            }
        }
    }
    // Any node not reached by 1 will not be part of inPosCycle as that node is still inf
    // so we just need to check whether it is possible to reach from n to any of this node
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (inPosCycle.find(curr) != inPosCycle.end()) {
            cout << "-1\n";
            return 0;
        }
        for (int& nhbr: rev_graph[curr]) {
            if (!visited[nhbr]) {
                visited[nhbr] = true;
                q.push(nhbr);
            }
        }
    }
    cout << res[n] << "\n";
    return 0;
}
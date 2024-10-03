#include <bits/stdc++.h>
using namespace std;
// dp[node] = max len path from node to n
// not possible to write it with for loop as the dependence is not clear so the definite for loop iterators wont be there
int64_t travel (vector<vector<int>>& graph, vector<int64_t>& dp, vector<int>& child, int node) {
    int n = graph.size();
    n--;
    if (node == n) {
        return dp[node] = 1ll;
    }
    if (dp[node] != -1) {
        return dp[node];
    }
    int64_t res = 0ll;
    for (int& nhbr: graph[node]) {
        int64_t curr = travel(graph, dp, child, nhbr);
        if (curr == 0ll) {
            // the mentioned path never reached n
            continue;
        }
        curr++;
        if (curr > res) {
            child[node] = nhbr; // we store this path
            res = curr;
        }
    }
    return dp[node] = res;
}
int main () {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<int64_t> dp(n+1, -1);
    vector<int> child(n+1, 0);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    int64_t res = travel(graph, dp, child, 1);
    if (res == 0ll) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        cout << res << "\n";
        int curr = 1;
        while (curr != 0) {
            cout << curr << ' ';
            curr = child[curr];
        }
        cout << "\n";
    }
    return 0;
}
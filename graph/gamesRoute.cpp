#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int travel(vector<vector<int>>& graph, vector<int>& dp, int node) {
    int n = graph.size();
    n--;
    if (node == n) {
        return dp[node] = 1;
    }
    if (dp[node] != -1) {
        return dp[node];
    }
    int res = 0;
    for (auto& nhbr: graph[node]) {
        ( res += travel(graph, dp, nhbr)) %= MOD; 
    }
    return dp[node] = res;
}
int main () {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<int> dp(n+1, -1);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    cout << travel(graph, dp, 1) << "\n";
    return 0;
}
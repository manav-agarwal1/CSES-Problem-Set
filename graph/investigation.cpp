#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const long long inf = LLONG_MAX;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n+1);
    priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<pair<int64_t, int64_t>>> pq;
    vector<bool> visited(n+1, false);
    vector<int> numWays(n+1, -1);
    vector<int> minF(n+1, 1e9);
    vector<int> maxF(n+1, 0);
    vector<int64_t> dist(n+1, inf);
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    pq.push({dist[1] = 0, 1});
    numWays[1] = 1;
    minF[1] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) {
            continue; // no point in repeated visits will increase cost
        }
        visited[u] = true;
        for (auto [v, w]: graph[u]) {
            if (dist[u] + w == dist[v]) {
                ( numWays[v] = numWays[u] + numWays[v] ) %= MOD;
                minF[v] = min(minF[v], minF[u]+1);
                maxF[v] = max(maxF[v], maxF[u]+1);
            }
            else if (dist[u] + w < dist[v]) {
                pq.push({dist[v] = dist[u]+w, v});
                numWays[v] = numWays[u];
                minF[v] = minF[u] + 1;
                maxF[v] = maxF[u] + 1;
            }
        }
    }
    cout << dist[n] << ' ' << numWays[n] << ' ' << minF[n] << ' ' << maxF[n] << "\n";
    return 0;
}
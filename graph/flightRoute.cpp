#include <bits/stdc++.h>
using namespace std;
const long long inf = LLONG_MAX;
/**
 * @brief Each city must be visited <=k times
 * 
 * @return int 
 */
int main () {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<long long, long long>>> graph(n+1);
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    vector<int> cnt(n+1, 0);
    vector<long long> res;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0ll, 1ll});
    while (!pq.empty() && res.size()<(size_t)k) {
        auto curr = pq.top();
        pq.pop();

        cnt[curr.second]++;
        if (curr.second == n) {
            res.push_back(curr.first);
        }
        if (cnt[curr.second] <= k) {
            for (auto& nhbr: graph[curr.second]) {
                pq.push({curr.first+nhbr.second, nhbr.first});
            }
        }
    }
    sort(res.begin(), res.end());
    for (auto& it: res) {
        cout << it << ' ';
    }
    cout << "\n";
    return 0;
}
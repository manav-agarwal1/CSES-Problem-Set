#include <bits/stdc++.h>
using namespace std;
const long long inf = LLONG_MAX;
struct node {
    int64_t cost;
    int64_t dst;
    bool used;
    bool operator<(const node& other) const {
        return cost > other.cost; // Min-heap: the lower cost has higher priority
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int64_t, int64_t>>> graph(n+1);
    vector<vector<int64_t>> dist(2, vector<int64_t>(n+1, inf));
    priority_queue<node> pq;
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    pq.push(node{0ll, 1, false});
    dist[false][1] = dist[true][1] = 0;
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        if (dist[curr.used][curr.dst] < curr.cost) {
            continue;
        }
        for (auto& nhbr: graph[curr.dst]) {
            int64_t c = nhbr.second;
            // if we have not used discount so far
            if (!curr.used) {
                // try using it
                if (dist[true][nhbr.first] > (curr.cost + c/2)) {
                    dist[true][nhbr.first] = curr.cost + c/2;
                    pq.push(node{dist[true][nhbr.first], nhbr.first, true});
                }
            }
            // irrespective we choose to save coupon
            if (dist[curr.used][nhbr.first] > (curr.cost + c)) {
                dist[curr.used][nhbr.first] = curr.cost + c;
                pq.push(node{dist[curr.used][nhbr.first], nhbr.first, curr.used});
            }
        }
    }
    cout << dist[true][n] << "\n";
    return 0;
}
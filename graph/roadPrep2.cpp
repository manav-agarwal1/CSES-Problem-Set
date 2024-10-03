#include <bits/stdc++.h>
using namespace std;
/**
 * @brief Kruskal
 * 
 * @return int 
 */
const int N = 2e5 + 1;
int parent[N];
int sz[N];
struct Edge {
    int u, v, w;
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};
void init(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}
int find(int a) {
    if (parent[a] == a) {
        return a;
    }
    return parent[a] = find(parent[a]);
}
void union_set(int a, int b) {
    a = find(a);
    b = find(b);
    if (a!=b) {
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> graph(m);
    init(n);
    for (int i = 0; i < m; i++) {
        cin >> graph[i].u >> graph[i].v >> graph[i].w;
    }
    int64_t res = 0ll;
    int tree = 0;
    sort(graph.begin(), graph.end());
    for (Edge& e: graph) {
        // cout << e.w << "\n";
        if (find(e.u) != find(e.v)) {
            res += e.w;
            tree++;
            if (tree == n-1) {
                cout << res << "\n";
                return 0;
            }
            union_set(e.u, e.v);
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
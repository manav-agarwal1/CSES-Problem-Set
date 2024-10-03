#include <bits/stdc++.h>
using namespace std;
/**
 * @brief DSU
 * 
 * @return int 
 */
const int N = 1e5 + 1;
int parent[N];
int sz[N];
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    init(n);
    int numComp = n, compSize = 1;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        if (find(u) == find(v)) {
            cout << numComp << ' ' << compSize << "\n";
        }
        else {
            union_set(u, v);
            numComp--;
            compSize = max(compSize, sz[find(u)]);
            cout << numComp << ' ' << compSize << "\n";
        }
    }

    return 0;

}
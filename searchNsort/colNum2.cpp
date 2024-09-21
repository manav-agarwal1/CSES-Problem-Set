#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> idx(n+1), a(n+1);
    for (int i = 1, temp; i <= n; i++) {
        cin >> temp;
        a[i] = temp;
        idx[temp] = i;
    }

    int res = 1;
    for (int i = 1; i < n; i++) {
        res += (idx[i+1] < idx[i]);
    }
    set<pair<int, int>> s;
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (a[x] < n) {
            s.insert({a[x], a[x]+1});
        }
        if (a[x] > 1) {
            s.insert({a[x]-1, a[x]});
        }
        if (a[y] < n) {
            s.insert({a[y], a[y]+1});
        }
        if (a[y] > 1) {
            s.insert({a[y]-1, a[y]});
        }
        for (auto &it: s) {
            res -= (idx[it.first] > idx[it.second]);

        }
        swap(a[x], a[y]);
        idx[a[x]] = x;
        idx[a[y]] = y;
        for (auto &it: s) {
            res += (idx[it.first] > idx[it.second]);

        }
        cout << res << endl;
        s.clear();
    }
    return 0;
}
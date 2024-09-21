#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> a(n);
    for (auto &it: a) {
        int x, y;
        cin >> x >> y;
        it.first = y;
        it.second = x;
    }
    sort(a.begin(), a.end());
    int res = 0;
    multiset<int> ed;
    for (int i = 0; i < k; i++) {
        ed.insert(0);
    }
    for (int i = 0; i < n; i++) {
        auto it = ed.upper_bound(a[i].second);
        if (it == ed.begin()) {
            continue;
        }
        advance(it, -1);
        ed.erase(it);
        ed.insert(a[i].first);
        ++res;
    }
    cout << res << endl;
    return 0;
}
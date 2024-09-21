#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (auto &it: a) {
        int x, y;
        cin >> x >> y;
        // store {end, st}
        it.first = y;
        it.second = x;
    }
    sort(a.begin(), a.end());
    int res = 0, time = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].second >= time) {
            res++;
            time = a[i].first;
        }
    }
    cout << res << endl;
    return 0;
}
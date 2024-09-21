#include <bits/stdc++.h>
using namespace std;
struct pr {
    int64_t s, e, m;
};
int main () {
    // what we earn before day i
    int n;
    cin >> n;
    vector<pr> a(n);
    map<int64_t, int64_t> day;
    for (auto &it: a) {
        cin >> it.s >> it.e >> it.m;
        it.e++;
        day[it.s] = 0;
        day[it.e] = 0;
    }
    int idx = 0;
    for (auto &it: day) {
        it.second = idx++;
    }
    vector<vector<pair<int64_t, int64_t>>> lookup(idx);
    for (int i = 0; i < n; i++) {
        // on i day all projects
        // cout << day[a[i].e] << endl;
        lookup[day[a[i].e]].push_back({day[a[i].s], a[i].m});
    }

    vector<int64_t> dp(idx+1, 0ll);
    // cout << idx << endl;
    for (int i = 1; i <= idx; i++) {
        dp[i] = dp[i-1];
        for (auto &it : lookup[i-1]) {
            // + 1 for idx 1 based
            dp[i] = max(dp[i], dp[it.first+1]+it.second);
        }
        // cout << i << ' ' << dp[i] << endl;
    }
    cout << dp[idx] << endl;
    return 0;
}
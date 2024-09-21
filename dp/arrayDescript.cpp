#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int main () {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<int>> dp(n, vector<int> (m+1, 0));
    // num ways to fill till idx i, if a[i]=j
    for (auto &it: a) {
        cin >> it;
    }

    if (a[0]==0) {
        fill(dp[0].begin(), dp[0].end(), 1); // we can have any value on the first index
    }
    else {
        dp[0][a[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (a[i]==0) {
            for (int j = 1; j <= m; j++) {
                for (int k: {j-1, j, j+1}) {
                    if (k>=1 && k<=m) {
                        (dp[i][j] += dp[i-1][k]) %= MOD;
                    }
                }
            }
            // cout << "check" << endl;
        }
        else {
            for (int k: {a[i]-1, a[i], a[i]+1}) {
                if (k>=1 && k <= m) {
                    (dp[i][a[i]] += dp[i-1][k]) %= MOD;
                }
            }
            // cout << "hi" << endl;
        }
        
    }
    
    int res = 0;
    for (int i = 1; i <= m; i++) {
        (res += dp[n-1][i]) %= MOD;
    }
    cout << res << endl;
    return 0;
}
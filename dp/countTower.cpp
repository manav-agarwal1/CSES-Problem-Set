#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
/**
 * @brief https://www.youtube.com/watch?v=51AkVn5Urno
 * 
 */
vector<vector<int64_t>> dp(1e6+1, vector<int64_t>(2, 0ll)); // number of ways to make tower of h = n and w = 2
int it = -1;
int helper(const int &n) {
    if (it > n) {
        // cout << "Here -> ";
        return (dp[n][0] + dp[n][1]) % MOD;
    }
    for (int i = it; i <= n; i++) {
        (dp[i][0] += (2*dp[i-1][0])%MOD) %= MOD;
        (dp[i][1] += (4*dp[i-1][1])%MOD) %= MOD;
        // cout << dp[i][0] << ' ' << dp[i][1] << endl;
        (dp[i][0] += dp[i-1][1]) %= MOD;
        (dp[i][1] += dp[i-1][0]) %= MOD;
        // cout << dp[i][0] << ' ' << dp[i][1] << endl;
    }

    return (dp[n][0] + dp[n][1]) % MOD;
}
int main () {
    int t, n;
    cin >> t;
    dp[1][0] = 1;
    dp[1][1] = 1;
    it = 2;
    while (t--) {
        cin >> n;
        // cout << it << ' ' << n << endl;
        cout << helper(n) << "\n";
        it = max(n+1, it);
        // cout << it << ' ' << n << endl;
    }
    return 0;
}
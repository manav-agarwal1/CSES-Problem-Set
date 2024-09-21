#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const int MAX = 1e5;
vector<vector<bool>> dp(N+1, vector<bool>(MAX+1, false));
int main () {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (auto &it: coins) {
        cin >> it;
    }
    // dp[i][i] = possible to make sum j with i coins
    dp[0][0] = true;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0, temp; j <= MAX; j++) {
            dp[i][j] = dp[i-1][j];
            temp = j - coins[i-1];
            if (temp >= 0 && dp[i-1][temp]) {
                dp[i][j] = true;
            }
            res += dp[n][j];
        }
    }
    res--; // for j = 0;
    cout << res << "\n";
    for (int j = 1; j <= MAX; j++) {
        if (dp[n][j]) {
            cout << j << ' ';
        }
    }
    cout << "\n";
    return 0;
}
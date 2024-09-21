#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int main () {
    int n;
    cin >> n;

    int sum = n*(n+1)/2;
    if (sum%2 == 1) {
        cout << 0 << "\n";
        return 0;
    }
    sum /= 2; //tgt
    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            ( dp[i][j] += dp[i-1][j] ) %= MOD;
            if (j >= i) {
                ( dp[i][j] += dp[i-1][j-i] ) %= MOD;
            }
        }
    }
    cout << dp[n][sum]%MOD << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int main() {
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (auto &it: c) {
        cin >> it;
    }
    vector<int> dp(x+1, 0);
    dp[0] = 1;
    sort(c.begin(), c.end()); // as max 100 coins only
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j<n && c[j]<=i; j++) {
            dp[i] = (dp[i] + dp[i-c[j]])%MOD;
        }
    }
    cout << dp[x]%MOD << endl;
    return 0;
}
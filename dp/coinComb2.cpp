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
    // in previous we went for all possible coins for every sum, in this we go through all possible sums for every coind
    for (int j = 0; j < n; j++) {
        for (int i = 1; i<=x; i++) {
            if (i >= c[j]) {
                dp[i] = (dp[i] + dp[i-c[j]])%MOD;
            }
        }
    }
    cout << dp[x]%MOD << endl;
    return 0;
}
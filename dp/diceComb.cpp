#include <bits/stdc++.h>
using namespace std;

// unordered_map<int, int> m;
const int MOD = 1e9+7;
int helper(int n) {
    // if (n==0) {
    //     return 1;
    // }
    // int res = 0;
    // for (int i = 1; i <= 6 && i <= n; i++) {
    //     if (m.find(n-i)==m.end()) {
    //         res = (res + helper(n-i))%MOD;
    //     }
    //     else {
    //         res = (res + m[n-i])%MOD;
    //     }

    // }
    // return m[n] = res%MOD;

    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6 && j <= i; j++) {
            dp[i] = (dp[i] + dp[i-j])%MOD;
        }
    }
    return dp[n]%MOD;
}

int main() {
    int n;
    cin >> n;
    cout << helper(n) << endl;
    return 0;
}
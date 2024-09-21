#include <bits/stdc++.h>
using namespace std;
// https://stackoverflow.com/questions/16699247/what-is-a-cache-friendly-code
// it will get TLE if you use dp[x+1][n+1]
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n);
    int minn = INT_MAX;
    int sum = 0;

    for (auto &it: h) {
        cin >> it;
        minn = min(minn, it);
        sum += it;
    }
    for (auto &it: s) {
        cin >> it;
    }
    x = min(x, sum);
    vector<int> dp(x+1, 0);
    for (int i = 0; i < n; i++) {
        // dp[i][j] = with j bucks and i books what is the max i can get
        // reverse this direction as anyway base case is all 0
        // and you need previous value for present value so dont want it overwritten before it is used
        for (int j = x; j >= min(x, minn); j--) {
            if (j >= h[i]) {
                dp[j] = max(dp[j-h[i]]+s[i], dp[j]);
            }       
        }
    }
    cout << dp[x] << endl;
    return 0;
}
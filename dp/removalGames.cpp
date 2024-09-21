#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    int64_t sum = 0ll;
    for (auto &it: a) {
        cin >> it;
        sum += it;
    }
    vector<vector<int64_t>> dp(n, vector<int64_t>(n, 0ll));
    for (int i = n-1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i==j) {
                dp[i][j] = a[i];
            }
            else {
                dp[i][j] = max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]);
            }
        }
    }
    cout << (sum+dp[0][n-1])/2 << endl;
    return 0;
}
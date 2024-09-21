#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    vector<int> dp(x+1, INT_MAX-1); // min number of coins with sum x
    for (auto &it: c) {
        cin >> it;
    }
    dp[0] = 0;
    sort(c.begin(), c.end()); // as max 100 coins only
    
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n && c[j] <= i; j++) {
            dp[i] = min(dp[i], dp[i-c[j]]+1);
        }
    }
    cout << ((dp[x]==INT_MAX-1) ? -1 : dp[x]) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it: a) {
        cin >> it;
    }
    vector<int> dp(n, 1); // length ending at each elem is atleast 1
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
    return 0;
}
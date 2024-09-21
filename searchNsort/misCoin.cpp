#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it: a) {
        cin >> it;
    }
    sort(a.begin(), a.end());
    int64_t res = 1ll;
    for (auto &it: a) {
        if (it > res) {
            cout << res << "\n";
            return 0;
        }
        res += it;
    }
    cout << res << "\n";
    return 0;
}
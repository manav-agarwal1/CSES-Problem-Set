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
    int tgt = a[n/2];
    int64_t res = 0ll;
    for (auto &it: a) {
        res += abs(tgt-it);
    }
    cout << res << endl;
    return 0;
}
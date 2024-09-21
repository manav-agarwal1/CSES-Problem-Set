#include <bits/stdc++.h>
using namespace std;
bool check(vector<int64_t> &a, int64_t &mid, int &t) {
    int64_t sum = 0ll;
    for (auto &it: a) {
        sum += mid/it;
        if (sum >= t) {
            return true;
        }
    }
    return false;
}
int main() {
    int n, t;
    cin >> n >> t;
    vector<int64_t> a(n);
    for (auto &it: a) {
        cin >> it;
    }
    int64_t lo = 0ll;
    int64_t hi = 1e18;
    int64_t res = 0ll;
    while (lo <= hi) {
        int64_t mid = lo + (hi - lo) / 2;
        if (check(a, mid, t)) {
            res = mid;
            hi = mid-1;
        }
        else {
            lo = mid+1;
        }
    }
    cout << res << endl;
    return 0;
}
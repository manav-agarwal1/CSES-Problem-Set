#include <bits/stdc++.h>
using namespace std;
bool check(const vector<int> &a, const int &x, int64_t &mid) {
    int arr_cnt = 0;
    int64_t sum = 0ll;
    for (auto &it: a) {
        if (it > mid) {
            return false;
        }
        if (sum+it > mid) {
            arr_cnt++;
            sum = 0;
        }
        sum += it;
    }
    arr_cnt += (sum!=0);
    return arr_cnt<=x;
}
int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    int64_t lo = 1ll;
    int64_t hi = 0ll;
    for (auto &it: a) {
        cin >> it;
        hi += it;
    }

    while (lo < hi) {
        int64_t mid = lo + (hi - lo) / 2;
        if (check(a, x, mid)) {
            hi = mid;
        }
        else {
            lo = mid+1;
        }
    }
    assert(hi==lo);
    cout << lo << endl;

    return 0;
}
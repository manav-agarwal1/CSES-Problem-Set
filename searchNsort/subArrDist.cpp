#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int main () {
    int n, k;
    cin >> n >> k;
    unordered_map<int, int, custom_hash> m;
    vector<int> a(n);
    int64_t res = 0ll;
    for (int i = 0, j = 0, cnt = 0; j < n; j++) {
        cin >> a[j];
        cnt += (m.find(a[j])==m.end() || m[a[j]]==0);
        while (cnt > k) {
            m[a[i]]--;
            cnt -= (m[a[i]] == 0);
            i++;
        }
        // cout << i << ' ' << j << endl;
        res += j-i+1; // num of subarrays ending at j
        m[a[j]]++;
    }
    cout << res << '\n';
    return 0;
}
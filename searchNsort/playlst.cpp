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
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& it: a) {
        cin >> it;
    }
    unordered_map<int, int, custom_hash> m;
    int win_st = 0;
    int res = 0;
    for (int i = 0, temp = 0; i < n; i++) {
        if (m.find(a[i])!=m.end() && m[a[i]]>=win_st) {
            // cout << "hi\n";
            win_st = m[a[i]]+1;
            temp = i-m[a[i]];
        }
        else {
            temp++;
        }
        m[a[i]] = i;
        res = max(res, temp);
    }
    cout << res << endl; 
    return 0;
}
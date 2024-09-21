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
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (auto &it: a) {
        cin >> it;
    }
    unordered_map<int, pair<int, int>, custom_hash> possible;
    for (int i = n-1; i >= 0; i--) {
        for (int j = i-1; j >= 0; j--) {
            int temp = t-a[i]-a[j];
            if (possible.find(temp) != possible.end()) {
                cout << i+1 << ' ' << j+1 << ' ' << possible[temp].first+1 << ' ' << possible[temp].second+1 << endl;
                return 0;
            }
        }
        for (int j = i+1; j < n; j++) {
            possible[a[i]+a[j]] = {i, j};
        }
    }
    
    cout << "IMPOSSIBLE\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int64_t sum = 0ll;
    int64_t maxx = 0ll;
    for (int64_t i = 0, it; i < n; i++) {
        cin >> it;
        maxx = max(maxx, it);
        sum += it;
    }
    cout << max(2*maxx, sum) << endl;
    return 0;
}
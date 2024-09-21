#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, prev, curr, res;
    res = 0ll;
    prev = curr = -1ll;
    cin >> n;
    for (int i = 0, temp; i < n; i++) {
        cin >> curr;
        if (prev != -1) {
            temp = max((int64_t)0, -(curr-prev));
            curr += temp;
            res += temp;
        }
        prev = curr;
    }
    cout << res << "\n";
    return 0;
}
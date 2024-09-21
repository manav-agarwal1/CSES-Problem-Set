#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int64_t res = LLONG_MIN;
    int64_t run_sum = 0ll;
    for (int i = 0, temp; i < n; i++) {
        cin >> temp;
        run_sum += temp;
        res = max(res, run_sum);
        run_sum = max(run_sum, (int64_t)0);
    }
    cout << res << endl;
    return 0;
}
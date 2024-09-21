#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int cnt = 0;
    int sum = 0;
    for (int i = 0, j = 0; j < n; j++) {
        cin >> a[j];
        sum += a[j];
        while (sum > x) {
            sum -= a[i];
            i++;
        }
        cnt += (sum==x);
    }
    cout << cnt << endl;
    return 0;
}
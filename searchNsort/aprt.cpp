#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (auto &it: a) {
        cin >> it;
    }
    for (auto &it: b) {
        cin >> it;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int res = 0;
    for (int i=0, j=0; i<n && j<m;) {
        // cout << i << ' ' << j << ' ' << res << endl;
        if (b[j]>=a[i]-k && b[j]<=a[i]+k) {
            i++;
            j++;
            res++;
        }
        else if (b[j]<a[i]-k) {
            j++;
        }
        else if(b[j]>a[i]+k) {
            i++;
        }
    }
    cout << res << "\n";
    return 0;
}
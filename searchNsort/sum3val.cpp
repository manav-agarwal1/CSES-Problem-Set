#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    int idx = 1;
    for (auto &it: a) {
        cin >> it.first;
        it.second = idx++;
    }
    sort(a.begin(), a.end());
    
    for (int i = 0, j, k; i < n-2; i++) {
        j = i+1;
        k = n-1;
        while (j < k) {
            int sum = a[i].first+a[j].first+a[k].first;
            if (sum==x) {
                cout << a[i].second << ' ' << a[j].second << ' ' << a[k].second << endl;
                return 0;
            }
            else if(sum > x) {
                k--;
            }
            else {
                j++;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
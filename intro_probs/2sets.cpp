#include <bits/stdc++.h>
using namespace std;
/**
 * @brief 
 * Just pick max elements until we cant
 * @return int 
 */
int main() {
    int64_t n;
    cin >> n;
    int64_t total = n*(n+1)/2;
    if (total%2 == 1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    total /= 2;
    int64_t sum1 = 0ll;
    int64_t curr = n;
    vector<bool> visited(n+1, false);
    vector<int> set1;
    while (sum1 < total) {
        int64_t temp = total - sum1;
        if (temp < curr) {
            set1.push_back(temp);
        }
        else {
            set1.push_back(curr);
            curr--;
        }
        sum1 += set1.back();
        visited[set1.back()] = true;
    }

    size_t setSz = set1.size();
    cout << setSz << endl;
    for (auto &it: set1) {
        cout << it << ' ';
    }
    cout << endl;
    cout << n - (int)setSz << endl;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << i << ' ';
        }
    }
    cout << endl;
    return 0;
}
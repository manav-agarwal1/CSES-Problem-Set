#include <bits/stdc++.h>
using namespace std;
/**
 * @brief 
 * @return int 
 */

int main() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 5; n >= i; i*=5) {
        res += n/i;
    }
    cout << res << endl;
    return 0;
}

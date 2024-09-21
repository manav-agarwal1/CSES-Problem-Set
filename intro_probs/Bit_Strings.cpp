#include <bits/stdc++.h>
using namespace std;
/**
 * @brief 
 * @return int 
 */
const int MOD = 1e9+7;
int exp(int64_t base, int pow) {
    int64_t res = 1ll;
    base = base%MOD;
    while (pow > 0) {
        if (pow%2 == 1) {
            res = (res*base)%MOD;
        }
        pow = pow >> 1;
        base = (base*base)%MOD;
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    cout << exp(2ll, n) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
/**
 * @brief 
 * If we place a knight in r,c then we cant place other one in (r+-1,c+-2) and (r+-2, c+-1); ie; a 3x2 or 2x3 block, so we just find number of these in these blocks in the k*k, as in each of 3x2 or 2x3 block we have 2 pair of corners
 * 
 * We can place first one in k*k ways and second one in k*k - 1 ways
 * The fight will only happen in the 2x3 or 3x2 block and number of those are (k-1)*(k-2) and (k-2)*(k-1).
 * @return int 
 */
int main() {
    int64_t n;
    cin >> n;
    for (int64_t k = 1ll, temp; k <= n; k++) {
        temp = k*k;
        cout << temp*(temp-1)/2 - (4*(k-1)*(k-2)) << endl;
    }
    return 0;
}
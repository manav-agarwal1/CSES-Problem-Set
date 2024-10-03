#include <bits/stdc++.h>
using namespace std;
/**
 * @brief Binary Jumping
 * table[k][i] = which node we arrive at if we jump from ith node back 2^k times
 * k = 0, means 2^0 = 1 jump so basically jump to parent
 * k+1 is build from k as 2^k*2^k = 2^(k+1)
 * Now if we have some non power of 2 then we can just break it to binary and do it
 * You start jumping from highest power of 2
 * 
 * @return int 
 */
const int MAX = 2e+5;
const int MAX_D = 30;
vector<vector<int>> binLiftTable(MAX_D, vector<int>(MAX, -1));
// log2(10^9) = 27... = MAX_D is fine
int jump (int node, int num) {
    for (int i = MAX_D-1; i >= 0; i--) {
        if (num&(1<<i)) {
            node = binLiftTable[i][node];
        }
    }
    return node;
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> binLiftTable[0][i]; // parent info in k = 0
    }
    for (int k = 1; k < MAX_D; k++) {
        for (int node = 1, mid; node <= n; node++) {
            mid = binLiftTable[k-1][node];
            binLiftTable[k][node] = binLiftTable[k-1][mid];
        }
    }
    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << jump(x, k) << "\n";
    }
    return 0;
}
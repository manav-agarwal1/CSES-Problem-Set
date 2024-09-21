#include <bits/stdc++.h>
using namespace std;
int64_t exp(int64_t base, int64_t pow) {
    int64_t res = 1ll;
    while (pow > 0) {
        if (pow % 2 == 1ll) {
            res = res * base;
        }
        pow = pow >> 1;
        base = base * base;
    }
    return res;
}

int main() {
    int64_t q;
    cin >> q;
    while (q--) {
        int64_t p;
        cin >> p;

        int64_t dig = 1ll;
        int64_t base = 9ll;

        // Identify the interval where the p-th digit is located
        while (true) {
            int64_t sub = dig * base;
            if (p - sub <= 0ll) {
                break;
            }
            p -= sub;
            base *= 10ll;
            dig++;
        }

        // Adjust p to be zero-based
        p--;

        // Calculate the target number and the specific digit index
        int64_t tgt = exp(10ll, dig - 1ll) + (p / dig);
        int idx = p % dig;

        // Convert the target number to string and find the required digit
        cout << to_string(tgt)[idx] << endl;
    }
    return 0;
}

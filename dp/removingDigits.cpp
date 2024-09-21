#include <bits/stdc++.h>
using namespace std;

int maxDigit(int n) {
    int max_digit = 0;

    // Handle negative numbers by taking the absolute value
    n = abs(n);

    while (n > 0) {
        int digit = n % 10;  // Extract the last digit
        max_digit = max(max_digit, digit);
        n /= 10;  // Remove the last digit from n
    }

    return max_digit;
}

int main() {
    int n;
    cin >> n;
    int res = 0;
    while (n) {
        res++;
        n -= maxDigit(n);
    }
    cout << res << endl;
    return 0;
}
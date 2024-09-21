#include <bits/stdc++.h>
using namespace std;

// Function to generate n-bit Gray code sequence
vector<string> generateGrayCode(int n) {
    vector<string> result;
    int num_sequences = 1 << n; // Total number of sequences is 2^n

    for (int i = 0; i < num_sequences; i++) {
        int gray = i ^ (i >> 1); // Generating Gray code
        string gray_code = bitset<32>(gray).to_string().substr(32 - n);
        result.push_back(gray_code);
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> gray_codes = generateGrayCode(n);

    for (const string& code : gray_codes) {
        cout << code << "\n";
    }
    
    return 0;
}

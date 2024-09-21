#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<string> solve(string S)
{
    sort(S.begin(), S.end());

    // set to store all the unique permutations
    vector<string> uniqueStrings;

    do {
        uniqueStrings.push_back(S);
    } while (next_permutation(S.begin(), S.end()));
    return uniqueStrings;
}
int main() 
{
    string s;
    cin >> s;
    auto uniqueStrings = solve(s);

    cout << uniqueStrings.size() << "\n";
    for (string& str : uniqueStrings) {
        cout << str << "\n";
    }

    return 0;
}
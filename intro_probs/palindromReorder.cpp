#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> count(26, 0);
    for (char& c: s) {
        count[c-'A']++;
    }
    int m = 0;
    for (int& n: count) {
        m += (n%2);
    }
    if (m>1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    string result;
    for (int i = 0; i < 26; i++){
        if(!(count[i]%2)){
            for(int j = 0; j < count[i]/2; j++) result.push_back(i + 'A');
        }
    }
    for (int i = 0; i < 26; i++){
        if(count[i]%2){
            for(int j = 0; j < count[i]; j++) result.push_back(i + 'A');
        }
    }
    for (int i = 25; i >= 0; i--){
        if(!(count[i]%2)){
            for(int j = 0; j < count[i]/2; j++) result.push_back(i + 'A');
        }
    }

    cout << result << endl;
    return 0;
}
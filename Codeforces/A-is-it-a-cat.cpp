// problem link
// https://codeforces.com/contest/1800/problem/A

#include<bits/stdc++.h>
using namespace std;

void Answer() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    // cout << s << endl;
    
    string uniq = "";
    for(auto &x: s) {
        if(x != uniq.back()) uniq += x;
    }
    cout << (uniq == "meow" ? "YES" : "NO") << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) Answer();
    
    return 0;
}
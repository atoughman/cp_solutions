// problem link
// https://codeforces.com/problemset/problem/1774/A

#include<bits/stdc++.h>
using namespace std;

void Answer() {
    int n;
    cin >> n;
    string s, ans="";
    cin >> s;
    
    int tot = s[0]-'0';
    for(int i=1; i<n; i++) {
        tot += s[i]-'0';
        if(tot == 2) {
            ans += "-";
            tot = 0;
        } else {
            ans += "+";
        }
    }
    
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) Answer();
    
    return 0;
}
// problem link
// https://codeforces.com/problemset/problem/1789/B

#include<bits/stdc++.h>
using namespace std;

void Answer() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<int> a;
    int l = 0;
    int r = n-1;
    while(l<r) {
        if(s[l] != s[r]) a.push_back(l);
        l += 1;
        r -= 1;
    }
    
    for(int i=1; i<a.size(); i++) {
        if(a[i] != a[i-1]+1) {
            cout << "No" << endl;
            return;
        }
    }
    
    cout << "Yes" << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) Answer();
    
    return 0;
}
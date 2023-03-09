// problem link
// https://codeforces.com/problemset/problem/1776/A

#include<bits/stdc++.h>
using namespace std;

void Answer() {
    int n;
    cin >> n;
    vector<int> v;
    v.push_back(0);
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    v.push_back(1440);
    
    int walks = 0;
    for(int i=1; i<v.size(); i++) {
        walks += (v[i]-v[i-1])/120;
    }
    
    if(walks >= 2) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) Answer();
    
    return 0;
}
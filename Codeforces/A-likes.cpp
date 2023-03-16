// problem link
// https://codeforces.com/problemset/problem/1802/A

#include<bits/stdc++.h>
using namespace std;

void Answer() {
    int n;
    cin >> n;
    int pos = 0;
    int neg = 0;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        if(a > 0) ++pos;
        else ++neg;
    }
    
    for(int i=1; i<=pos; i++) {
        cout << i << ' ';
    }
    
    for(int i=1; i<=n-pos; i++) {
        cout << pos-i << ' ';
    }
    cout << endl;
    
    for(int i=0; i<neg; i++) {
        cout << "1 0 ";
    }
    
    for(int i=1; i<=pos-neg; i++) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) Answer();
    
    return 0;
}
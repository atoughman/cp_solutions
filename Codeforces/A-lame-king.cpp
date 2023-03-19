// problem link
// https://codeforces.com/problemset/problem/1804/A

#include<bits/stdc++.h>
using namespace std;

void Answer() {
    int a,b;
    cin >> a >> b;
    a = abs(a);
    b = abs(b);
    if(a == b) cout << a+b << endl;
    else {
        if(a < b) swap(a,b);
        a -= b;
        cout << 2*b+a+a-1 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) Answer();
    
    return 0;
}
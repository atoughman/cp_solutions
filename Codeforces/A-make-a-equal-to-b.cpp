// problem link
// https://codeforces.com/problemset/problem/1736/A

#include<bits/stdc++.h>
using namespace std;

void Answer() {
    int n;
    cin >> n;
    
    int a[n], b[n];
    int a1=0, b1=0, unmatch=0;
    
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    for(int i=0; i<n; i++) {
        if(a[i] != b[i]) unmatch += 1;
        if(a[i] == 1) a1 += 1;
        if(b[i] == 1) b1 += 1;
    }
    
    int toggle_and_rearrange = abs(a1-b1) + 1;
    int toggle_only = unmatch;
    
    cout << min(toggle_only, toggle_and_rearrange) << endl;
}

int main() {
    int t = 1;
    cin >> t;
    
    while(t--) Answer();
    
    return 0;
}
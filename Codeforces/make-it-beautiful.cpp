// problem link
// https://codeforces.com/problemset/problem/1783/A

#include<bits/stdc++.h>
using namespace std;

void Answer() {
    int n;
    cin >> n;
    int ar[n];
    for(int i=0; i<n; i++) cin >> ar[i];
    sort(ar, ar+n);
    
    if(ar[0] == ar[n-1]) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    
    cout << ar[0] << ' ';
    for(int i=n-1; i>0; i--) cout << ar[i] << ' ';
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) Answer();
    
    return 0;
}
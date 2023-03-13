// problem link
// https://codeforces.com/problemset/problem/1784/A

#include<bits/stdc++.h>
using namespace std;

void Answer() {
    int n;
    cin >> n;
    int ar[n];
    for(int i=0; i<n; i++) cin >> ar[i];
    sort(ar, ar+n);
    int ct = 1;
    long long ans = 0;
    
    for(int i=0; i<n; i++) {
        if(ar[i] < ct) continue;
        if(ar[i] > ct) {
            ans = ans + ar[i] - ct;
        }
        ++ct;
    }
    
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) Answer();
    
    return 0;
}
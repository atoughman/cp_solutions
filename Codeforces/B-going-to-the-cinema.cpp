// problem link
// https://codeforces.com/problemset/problem/1781/B

#include<bits/stdc++.h>
using namespace std;

void Answer() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    int ans = a[0] == 0 ? 0: 1;
    bool batch_started = false;
    
    for(int i=0; i<n; i++) {
        if(i >= a[i]) {
            if(batch_started) continue;
            else {
                ans += 1;
                batch_started = true;
            }
        } else {
            batch_started = false;
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
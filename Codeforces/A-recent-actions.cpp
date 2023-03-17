// problem link
// https://codeforces.com/problemset/problem/1799/A

#include<bits/stdc++.h>
using namespace std;

void Answer() {
    int n,m;
    cin >> n >> m;
    unordered_map<int, int> mp;
    int v[n];
    memset(v, -1, sizeof(v));
    int cur = n-1;
    
    for(int i=1; i<=m; i++) {
        int a;
        cin >> a;
        if(cur >= 0 and mp.find(a) == mp.end()) {
            v[cur] = i;
            cur -= 1;
        }
        mp[a] = 1;
    }
    
    for(auto &x: v) cout << x << ' ';
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) Answer();
    
    return 0;
}
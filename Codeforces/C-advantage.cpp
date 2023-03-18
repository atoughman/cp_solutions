// problem link
// https://codeforces.com/problemset/problem/1760/C

#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

void Answer() {
    int n;
    cin >> n;
    int ar[n];
    for(int i=0; i<n; i++) cin >> ar[i];
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto &x: ar) {
        pq.push(x);
        if(pq.size() > 2) pq.pop();
    }
    int mx2 = pq.top();
    pq.pop();
    int mx1 = pq.top();
    
    for(auto &x: ar) {
        if(x == mx1) cout << x-mx2 << ' ';
        else cout << x-mx1 << ' ';
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) Answer();
    
    return 0;
}
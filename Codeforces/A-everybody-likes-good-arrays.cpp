// problem link
// https://codeforces.com/contest/1777/problem/A

#include<bits/stdc++.h>
using namespace std;

void Answer() {
    int n;
    cin >> n;
    
    int ar[n];
    for(int i=0; i<n; i++) {
        cin >> ar[i];
        ar[i] %= 2;
    }
    
    int pairs = 0;
    for(int i=1; i<n; i++) {
        if(ar[i-1] == ar[i]) ++pairs;
    }
    
    cout << pairs << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) Answer();
    
    return 0;
}
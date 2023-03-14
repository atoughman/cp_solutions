// problem link
// https://www.codechef.com/problems/AUDIBLE

#include<bits/stdc++.h>
using namespace std;

void Answer() {
    int x;
    cin >> x;
    if(x >= 67 and x <= 45000) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t = 1;
    cin >> t;
    
    while(t--) Answer();
    
    return 0;
}
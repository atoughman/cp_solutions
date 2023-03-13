// problem link
// https://www.codechef.com/problems/GDTURN

#include<bits/stdc++.h>
using namespace std;

void Answer() {
    int x,y;
    cin >> x >> y;
    if(x+y > 6) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t = 1;
    cin >> t;
    
    while(t--) Answer();
    
    return 0;
}
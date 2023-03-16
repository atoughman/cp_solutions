// problem link
// https://www.codechef.com/problems/TAXSAVING

#include<bits/stdc++.h>
using namespace std;

void Answer() {
    int y,x;
    cin >> x >> y;
    
    cout << max(0, x-y) << endl;
}

int main() {
    int t = 1;
    cin >> t;
    
    while(t--) Answer();
    
    return 0;
}
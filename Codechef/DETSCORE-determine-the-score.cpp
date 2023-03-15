// problem link
// https://www.codechef.com/problems/DETSCORE

#include<bits/stdc++.h>
using namespace std;

void Answer() {
    int x,n;
    cin >> x >> n;
    cout << (x/10)*n << endl;
}

int main() {
    int t = 1;
    cin >> t;
    
    while(t--) Answer();
    
    return 0;
}
// problem link
// https://codeforces.com/contest/1780/problem/A

#include<bits/stdc++.h>
using namespace std;

void Answer() {
    int n;
    cin >> n;
    vector<int> odd, even;
    for(int i=1; i<=n; i++) {
        int a;
        cin >> a;
        if(a % 2 == 0) even.push_back(i);
        else odd.push_back(i);
    }
    
    if((odd.size() == 2 and even.size() == 1) or odd.size() == 0) {
        cout << "NO" << endl;
        return;
    }
    
    cout << "YES" << endl;
    if(odd.size() > 2) {
        cout << odd[0] << ' ' << odd[1] << ' ' << odd[2] << endl;
    } else {
        cout << odd[0] << ' ' << even[0] << ' ' << even[1] << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) Answer();
    
    return 0;
}
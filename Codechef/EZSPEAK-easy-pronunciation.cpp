// problem link
// 

#include<bits/stdc++.h>
using namespace std;

bool isVowel(char ch) {
    vector<char> v = {'a','e','i','o','u'};
    for(int i=0; i<v.size(); i++) {
        if(ch == v[i]) return true;
    }
    return false;
}

void Answer() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int ct = 0;
    
    for(int i=0; i<n; i++) {
        if(isVowel(s[i])) {
            ct = 0;
        } else {
            ct += 1;
        }
        
        if(ct >= 4) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t = 1;
    cin >> t;
    
    while(t--) Answer();
    
    return 0;
}
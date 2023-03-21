// problem link
// https://codeforces.com/contest/1794/problem/A

#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(const string& s) {
    string r = s;
    reverse(r.begin(), r.end());
    return s == r;
}
 
void Answer() {
    int n;
    cin >> n;
    vector<string> v;
    vector<string> possible_s;
    for (int i = 0; i < 2 * n - 2; i++) {
        string a;
        cin >> a;
        if(a.size() == n-1) v.push_back(a);
    }
    // cout << v[0] << ' ' << v[1] << endl;
    
    if(v[0].size() == 1) {
        possible_s.push_back(v[0]+v[1]);
    } else {
        if(v[0].substr(1, n-2) == v[1].substr(0, n-2)) {
            possible_s.push_back(v[0]+v[1].back());
        }
        if(v[1].substr(1, n-2) == v[0].substr(0, n-2)) {
            possible_s.push_back(v[1]+v[0].back());
        }
    }
    
    for(auto &x: possible_s) {
        // cout << x << endl;
        if(is_palindrome(x)) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        Answer();
    }
    return 0;
}
// problem link
// https://leetcode.com/problems/reverse-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<char> &s, int l, int r) {
        if(l>=r) return;
        else {
            swap(s[l], s[r]);
            solve(s, l+1, r-1);
        }
    }
    void reverseString(vector<char>& s) {
        solve(s, 0, s.size()-1);
    }
};
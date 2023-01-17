// problem link
// https://leetcode.com/problems/largest-number/description/

#include<bits/stdc++.h>
using namespace std;

bool comp(string a, string b) {
    string A = a+b;
    string B = b+a;
    if(A > B) return true;
    else return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        // int to string
        for(auto x: nums) {
            stringstream a;
            a << x;

            string s;
            a >> s;
            v.push_back(s);
        }

        sort(v.begin(), v.end(), comp);
        string ans = "";
        for(auto x: v) ans += x;

        // removing starting zeros
        int ct = 0;
        for(auto x: ans) {
            if(x == '0') ++ct;
            else break;
        }

        if(ct == ans.size()) return "0";
        else return ans.substr(ct, ans.size()-ct);
    }
};
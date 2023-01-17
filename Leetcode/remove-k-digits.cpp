// problem link
// https://leetcode.com/problems/remove-k-digits/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(auto &x: num) {
            while(k>0 && !st.empty() and st.top() > x) {
                st.pop();
                --k;
            }
            st.push(x);
        }

        while(k > 0 && !st.empty()) {
            st.pop();
            --k;
        }

        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        // remove spaces from front as they don't make sense
        int ct = 0;
        for(auto x: ans) {
            if(x == '0') ++ct;
            else break;
        }        

        if(ans.size() == ct) return "0";
        else return ans.substr(ct, ans.size()-ct);
    }
};
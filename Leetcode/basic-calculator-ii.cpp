// problem link
// https://leetcode.com/problems/basic-calculator-ii/description/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    bool is_num(char ch) {
        return ch >= '0' && ch <= '9';
    }

    int calculate(string s) {
        stack<ll> st;
        ll num = 0;
        char prev_op = '+';
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ') continue;

            if(is_num(s[i])) {
                num = num * 10 + s[i] - '0';
            } else {
                if(!st.empty()) {
                    ll prev = st.top();
                    if(prev_op == '/') {
                        st.pop();
                        num = prev / num;
                    }
                    else if(prev_op == '*') {
                        st.pop();
                        num = prev * num;
                    }
                    else if(prev_op == '-') {
                        num = -num;
                    }
                }
                prev_op = s[i];
                st.push(num);
                num = 0;
            }
        }
        if(!st.empty()) {
            ll prev = st.top();
            if(prev_op == '/') {
                st.pop();
                num = prev / num;
            }
            else if(prev_op == '*') {
                st.pop();
                num = prev * num;
            }
            else if(prev_op == '-') {
                num = -num;
            }
        }
        st.push(num);

        int ans = 0;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
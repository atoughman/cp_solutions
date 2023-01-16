// problem link
// https://leetcode.com/problems/reverse-words-in-a-string/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        stack<string> st;
        string so_far = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] != ' ') so_far += s[i];

            if(s[i] == ' ' or i+1 == s.size()) {
                if(!so_far.empty()) {
                    st.push(so_far);
                    so_far = "";
                }
            }
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();

            if(!st.empty()) ans += ' ';
        }

        return ans;
    }
};
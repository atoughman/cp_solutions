// problem link
// https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1

#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    string printMinNumberForPattern(string S){
        stack<char> st;
        st.push('1');
        string ans = "";
        
        for(int i=0; i<=S.size(); i++) {
            if(i == S.size() || S[i] == 'I') {
                while(!st.empty()) {
                    ans += st.top();
                    st.pop();   
                }
            }
            // pushing next number in form of charachter
            st.push('0'+i+2);
        }
        
        return ans;
    }
};
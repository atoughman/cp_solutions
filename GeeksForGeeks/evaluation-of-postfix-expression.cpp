// problem link
// 

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> st;
        
        for(auto &x: S) {
            if(x >= '0' and x <= '9') {
                st.push(x-'0');
                continue;
            }
            
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            switch(x) {
                case '+':
                    st.push(a+b);
                    break;
                case '-':
                    st.push(a-b);
                    break;
                case '*':
                    st.push(a*b);
                    break;
                case '/':
                    st.push(a/b);
                    break;
            }
        }
        return st.top();
    }
};
// problem link
// https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    unordered_map<char, int> prec = {
        {'^', 3},
        {'*', 2},
        {'/', 2},
        {'+', 1},
        {'-', 1}
    };
    
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        stack<char> st;
        string post = "";
        
        for(auto &x: s) {
            if(x == '(') {
                st.push(x);
                continue;
            }

            if(x == ')') {
                while(st.top() != '(') {
                    post += st.top();
                    st.pop();
                }
                st.pop();
                continue;
            }

            if(x == '+' or x == '-' or x == '*' or x == '/' or x == '^') {
                while(!st.empty() and prec[st.top()] >= prec[x]) {
                    post += st.top();
                    st.pop();
                }
                st.push(x);
                continue;
            }
            
            post += x;
        }
        
        while(!st.empty()) {
            post += st.top();
            st.pop();
        }
        
        return post;
    }
};
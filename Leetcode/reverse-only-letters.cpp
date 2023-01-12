#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_english(char ch)
    {
        return (ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z');
    }

    string reverseOnlyLetters(string s)
    {
        stack<char> st;
        for (auto &x : s)
        {
            if (is_english(x))
                st.push(x);
        }

        for (int i = 0; i < s.size(); i++)
            if (is_english(s[i]))
            {
                s[i] = st.top();
                st.pop();
            }

        return s;
    }
};
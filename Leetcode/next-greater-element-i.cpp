// problem link
// https://leetcode.com/problems/next-greater-element-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> ump;
        stack<int> st;

        for (auto &x : nums2)
        {
            while (!st.empty())
            {
                if (st.top() < x)
                {
                    ump[st.top()] = x;
                    st.pop();
                }
                else
                    break;
            }
            st.push(x);
        }
        while (!st.empty())
        {
            ump[st.top()] = -1;
            st.pop();
        }

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(ump[nums1[i]]);
        }

        return ans;
    }
};

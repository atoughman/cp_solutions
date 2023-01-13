// problem link
// https://leetcode.com/problems/next-greater-element-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> ans(nums.size(), -1);
        stack<int> st;
        for (int k = 0; k < 2; k++)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                while (!st.empty())
                {
                    if (nums[st.top()] < nums[i])
                    {
                        ans[st.top()] = nums[i];
                        st.pop();
                    }
                    else
                        break;
                }

                st.push(i);
            }
        }

        return ans;
    }
};
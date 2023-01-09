#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int mul = 1;
        int zeros = 0;
        for (auto &x : nums)
        {
            if (x == 0)
            {
                zeros++;
            }
            else
                mul *= x;
        }

        vector<int> ans;
        for (auto &x : nums)
        {
            if (zeros == 0)
                ans.push_back(mul / x);
            else if (zeros == 1)
            {
                if (x == 0)
                    ans.push_back(mul);
                else
                    ans.push_back(0);
            }
            else
                ans.push_back(0);
        }

        return ans;
    }
};
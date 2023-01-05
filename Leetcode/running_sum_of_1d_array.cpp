#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> ans;
        int so_far = 0;
        for (auto &x : nums)
        {
            so_far += x;
            ans.push_back(so_far);
        }
        return ans;
    }
};
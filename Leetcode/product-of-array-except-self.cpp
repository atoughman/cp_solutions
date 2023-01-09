#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> v;
        v.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            v.push_back(v.back() * nums[i]);
        }

        int right_mul = 1;
        for (int i = nums.size() - 1; i > 0; i--)
        {
            v[i] = v[i - 1] * right_mul;
            right_mul *= nums[i];
        }

        v[0] = right_mul;

        return v;
    }
};
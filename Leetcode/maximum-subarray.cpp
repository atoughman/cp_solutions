#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int so_far = nums[0];
        for (auto &x : nums)
        {
            sum = max(sum + x, x);
            so_far = max(so_far, sum);
        }

        return so_far;
    }
};
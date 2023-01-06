#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> num_with_index;

        for (int i = 0; i < nums.size(); i++)
            num_with_index.push_back({nums[i], i});

        sort(num_with_index.begin(), num_with_index.end());

        int l = 0;
        int r = nums.size() - 1;

        while (l < r)
        {
            int left_val = num_with_index[l].first;
            int right_val = num_with_index[r].first;
            int total = left_val + right_val;

            if (total == target)
                return {num_with_index[l].second, num_with_index[r].second};
            if (total < target)
                ++l;
            else
                --r;
        }

        // will never reach here.
        return {-1, -1};
    }
};
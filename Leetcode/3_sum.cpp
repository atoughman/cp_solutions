#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i == 0 or nums[i] != nums[i - 1])
            {
                int target = -1 * nums[i];

                // 2 sum
                int l = i + 1;
                int r = nums.size() - 1;
                while (l < r)
                {
                    if (nums[l] + nums[r] > target)
                    {
                        --r;
                    }
                    else if (nums[l] + nums[r] < target)
                    {
                        ++l;
                    }
                    else
                    {
                        ans.push_back({nums[i], nums[l], nums[r]});
                        while (l < r and nums[l] == nums[l + 1])
                            l++;
                        while (l < r and nums[r] == nums[r - 1])
                            --r;
                        ++l;
                        --r;
                    };
                }
            }
        }
        return ans;
    }
};
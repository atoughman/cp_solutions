#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i]) - 1] < 0)
            {
                // means its already modified once by similar value, that means i found duplicate
                ans.push_back(abs(nums[i]));
            }
            else
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }

        return ans;
    }
};
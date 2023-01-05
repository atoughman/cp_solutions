#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        vector<int> pref;

        int so_far = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            so_far += nums[i];
            pref.push_back(so_far);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int l_sum = i - 1 >= 0 ? pref[i - 1] : 0;
            int r_sum = pref[nums.size() - 1] - pref[i];
            if (l_sum == r_sum)
                return i;
        }
        return -1;
    }
};
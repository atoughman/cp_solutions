#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            // make decisions where you are sure of,
            // we are sure of what values occur in increasing slopes
            // check increasing slope side, and not the side which has crash point 6,7 then suddenly 0,1
            if (nums[mid] == target)
                return mid;
            if (nums[l] <= nums[mid])
            { // this is increasing side
                if (nums[l] <= target and target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if (nums[mid] < target and target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }

        return -1;
    }
};
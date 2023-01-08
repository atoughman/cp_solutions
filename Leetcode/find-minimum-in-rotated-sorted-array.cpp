#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        // if rotated m * size of vector, where m can be any whole number, it can be considered as not rotated at all
        // -> 1 2 3 5 7 9
        if (nums.front() <= nums.back())
            return nums.front();

        // else : 5 7 9 1 2 3
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (nums[l] > nums[mid])
            {
                r = mid;
            }
            else
                l = mid;
            if (mid + 1 < nums.size() and nums[mid] >= nums[mid + 1])
                return nums[mid + 1];
            if (mid - 1 >= 0 and nums[mid - 1] >= nums[mid])
                return nums[mid];
        }

        // will never reach here
        return -1;
    }
};
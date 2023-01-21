// problem link
// https://leetcode.com/problems/sort-colors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int cur = 0;

        while(cur <= r) {
            if(nums[cur] == 0) {
                swap(nums[l], nums[cur]);
                ++l;
                ++cur;
            } else if(nums[cur] == 2) {
                swap(nums[cur], nums[r]);
                --r;
            } else ++cur;
        }
    }
};
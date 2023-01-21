// problem link
// https://leetcode.com/problems/squares-of-a-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(auto &x: nums) x *= x;

        int l = 0;
        int r = n - 1;
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--) {
            if(nums[l] < nums[r]) {
                ans[i] = nums[r];
                --r;
            } else {
                ans[i] = nums[l];
                ++l;
            }
        }

        return ans;
    }
};
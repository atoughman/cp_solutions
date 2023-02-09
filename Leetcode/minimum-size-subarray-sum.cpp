// problem link
// https://leetcode.com/problems/minimum-size-subarray-sum/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int ans = INT_MAX;
        int sum = 0;
        while(r < n) {
            sum += nums[r];
            while(sum >= target) {
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l += 1;
            }
            r += 1;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
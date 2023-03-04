// problem link
// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll ans = 0;
        int r = 0;
        int n = nums.size();
        ll mini = -1;
        ll maxi = -1;
        ll valid_start = -1;

        while(r<n) {
            if(nums[r] < minK or nums[r] > maxK) { // problem
                // reset
                mini = -1;
                maxi = -1;
                valid_start = -1;
            } else {
                if(valid_start == -1) valid_start = r;
                if(nums[r] == minK) mini = r;
                if(nums[r] == maxK) maxi = r;
                if(mini != -1 and maxi != -1) { // add number of valid subarrays including current index
                    ans += min(mini, maxi) - valid_start + 1;
                }
            }
            r += 1;
        }

        return ans;
    }
};
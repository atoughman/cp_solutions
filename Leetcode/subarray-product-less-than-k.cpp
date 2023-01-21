// problem link
// https://leetcode.com/problems/subarray-product-less-than-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k < 2) return 0;

        int ans = 0;
        int pro = 1;
        int l = 0;
        int r = 0;

        for(int r=0; r<nums.size(); r++) {
            pro *= nums[r];
            while(pro >=k) {
                pro /= nums[l];
                ++l;
            }
            ans += r-l+1;
        }

        return ans;
    }
};
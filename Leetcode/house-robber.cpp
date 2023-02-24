// problem link
// https://leetcode.com/problems/house-robber/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        // l2 , l1, cur
        int l2 = nums[0];
        int l1 = max(nums[0], nums[1]);
        int i = 2;
        while(i<nums.size()) {
            int so_far = max(l1, l2+nums[i]);
            l2 = l1;
            l1 = so_far;
            i += 1;
        }

        return l1;
        
    }
};
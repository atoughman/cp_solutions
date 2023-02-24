// problem link
// https://leetcode.com/problems/house-robber/description/

#include<bits/stdc++.h>
using namespace std;

// ------------------- recursion + memo

const int mxn = 100 + 5;
class Solution {
public:
    int dp[mxn];

    int solve(int i, vector<int>& nums) {
        if(i<0) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(solve(i-2, nums) + nums[i], solve(i-1, nums));
    }

    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums.size()-1, nums);
    }
};
// ======================================================

// ------------------- Iterative + memo

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int dp[n];
        dp[0] = nums[0];
        dp[1] = max(nums[1], dp[0]);

        for(int i=2; i<n; i++) {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }

        return dp[n - 1];
    }
};
// ======================================================

// ------------------- Iterative + vars [ BEST ]

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
// ======================================================
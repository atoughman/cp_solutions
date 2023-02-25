// problem link
// https://leetcode.com/problems/min-cost-climbing-stairs/description/

#include<bits/stdc++.h>
using namespace std;

// ---------------------------- RECURSIVE
class Solution {
public:
    int solve(int i, vector<int>& cost) {
        if(i<0) return 0;
        return min(solve(i-1, cost), solve(i-2, cost)) + cost[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        return solve(cost.size()-1, cost);
    }
};

// ---------------------------- RECURSIVE + MEMO
const int mxn = 1e3+5;
class Solution {
public:
    int dp[mxn];
    int solve(int i, vector<int>& cost) {
        if(i<0) return 0;
        if(dp[i] != -1) return dp[i];
        
        return dp[i] = min(solve(i-1, cost), solve(i-2, cost)) + cost[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        cost.push_back(0);
        return solve(cost.size()-1, cost);
    }
};

// ---------------------------- ITERATIVE + MEMO
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n = cost.size();
        int dp[n];
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2; i<n; i++) {
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }

        return dp[n-1];
    }
};

// ---------------------------- ITERATIVE + N VARS [ BEST ]
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n = cost.size();
        int l2 = cost[0];
        int l1 = cost[1];

        for(int i=2; i<n; i++) {
            int so_far = min(l1, l2) + cost[i];
            l2 = l1;
            l1 = so_far;
        }

        return l1;
    }
};
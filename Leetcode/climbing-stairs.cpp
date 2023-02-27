// problem link
// https://leetcode.com/problems/climbing-stairs/description/

#include<bits/stdc++.h>
using namespace std;

// -------------   ITARTIVE + 1-D MEMO
class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1]+ dp[i-2];
        }

        return dp[n];
    }
};


// ---------------------- ITERATIVE + N VARS
class Solution {
public:
    int climbStairs(int n) {
        int l2 = 1;
        int l1 = 1;
        for(int i=2; i<=n; i++) {
            int cur = l2 + l1;
            l2 = l1;
            l1 = cur;
        }

        return l1;
    }
};
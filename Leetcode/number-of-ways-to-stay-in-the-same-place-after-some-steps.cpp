// problem link
// https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/

#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

// optimization 2, understanding the amount of space required
const int mxn = 250 + 3;
const int mxs = 500 + 3;

class Solution {
public:
    int dp[mxs][mxn];
    int solve(int i, int steps, int n) {
        // base case
        if(steps == 0) return dp[steps][i] = i == 0 ? 1 : 0;

        // already solved
        if(dp[steps][i] != -1) return dp[steps][i];

        int ans = 0;
        for(int dir=-1; dir<=1; dir++) {
            int I = i + dir;
            
            // optimization 1 : Truncating unneccessary steps
            if(I >= steps) continue;
            
            if(I >=0 and I<n) {
                ans += solve(I, steps-1, n);
                ans %= MOD;
            }
        }

        return dp[steps][i] = ans;
    }

    int numWays(int steps, int arrLen) {
        memset(dp, -1, sizeof(dp));
        return solve(0, steps, arrLen);
    }
};
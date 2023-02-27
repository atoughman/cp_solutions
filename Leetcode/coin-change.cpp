// problem link
// https://leetcode.com/problems/coin-change/description/

#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0] = 0;

        for(int i=1; i<=amount; i++) {
            int mn = INF;
            for(auto &x: coins) {
                if(x > i) continue;
                mn = min(mn, dp[i - x]);
            }
            if(mn != INF) dp[i] = mn + 1;
            else dp[i] = INF;
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }
};
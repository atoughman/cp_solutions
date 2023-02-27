// problem link
// https://leetcode.com/problems/2-keys-keyboard/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int dp[n+1];
        dp[1] = 0;
        for(int i=2; i<=n; i++) {
            dp[i] = i;
            for(int j=2; j<=i; j++) { // searching for factors
                if(i%j == 0) {
                    dp[i] = min(dp[i], dp[i/j]+j);
                }
            }
        }

        return dp[n];
    }
};
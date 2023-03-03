// problem link
// https://leetcode.com/problems/longest-palindromic-subsequence/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        int n = s.size();
        int dp[n+1][n+1];

        for(int i=0; i<n; i++) dp[i][0] = 0;
        for(int i=0; i<n; i++) dp[0][i] = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(s[i-1] == rev[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][n];

    }
};
// problem link
// https://leetcode.com/problems/longest-common-subsequence/description/

#include<bits/stdc++.h>
using namespace std;

////////////   RECURSIVE  + 2-D MEMO

const int mxn = 1e3+3;

class Solution {
public:
    int dp[mxn][mxn];
    int solve(int i1, int i2, string& s1, string& s2) {
        // base
        if(i1 == s1.size() or i2 == s2.size()) return 0;

        if(dp[i1][i2] != -1) return dp[i1][i2];

        if(s1[i1] == s2[i2]) return dp[i1][i2] = solve(i1+1, i2+1, s1, s2) + 1;
        else {
            return dp[i1][i2] = max(solve(i1, i2+1, s1, s2), solve(i1+1, i2, s1, s2));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        if(text1.size() < text2.size()) swap(text1, text2);
        return solve(0, 0, text1, text2);
    }
};


//////////          ITERATIVE + 2-D MEMO

class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.size();
        int m = b.size();

        int dp[n+1][m+1];
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int j=0; j<=m; j++) dp[0][j] = 0;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                
            }
        }

        return dp[n][m];
    }
};


////////   ITERATIVE + 1-D MEMO

class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.size();
        int m = b.size();

        vector<int> dp(m+1, 0);
        vector<int> new_dp(m+1);
        
        for(int i=1; i<=n; i++) {
            new_dp[0] = 0;

            for(int j=1; j<=m; j++) {
                if(a[i-1] == b[j-1]) {
                    new_dp[j] = dp[j-1] + 1;
                } else {
                    new_dp[j] = max(dp[j], new_dp[j-1]);
                }
                
            }
            swap(dp, new_dp);
        }

        return dp[m];
    }
};
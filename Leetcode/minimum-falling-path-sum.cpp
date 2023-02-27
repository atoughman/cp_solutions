// problem link
// https://leetcode.com/problems/minimum-falling-path-sum/description/

#include<bits/stdc++.h>
using namespace std;
//------------------------  RECURSIVE
const int INF = INT_MAX;

class Solution {
public:
    int n;

    bool inside(int row, int col) {
        return row >= 0 and col >= 0 and row < n and col < n;
    }

    int solve(int row, int col, vector<vector<int>>& matrix) {
        // base case
        if(!inside(row, col)) return INF;
        if(row == 0) return matrix[row][col];

        int mn = INF;
        for(int i=-1; i<2; i++) {
            mn = min(mn, solve(row-1, col+i, matrix));
        }

        return mn + matrix[row][col];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();

        int ans = INF;
        for(int col=0; col<n; col++) {
            ans = min(ans, solve(n-1, col, matrix));
        }

        return ans;
    }
};


//------------------------  RECURSIVE + 2-D MEMO
const int INF = INT_MAX;
const int mxn = 1e2 + 3;

class Solution {
public:
    int n;
    int dp[mxn][mxn];

    bool inside(int row, int col) {
        return row >= 0 and col >= 0 and row < n and col < n;
    }

    int solve(int row, int col, vector<vector<int>>& matrix) {
        // base case
        if(!inside(row, col)) return INF;
        if(row == 0) return dp[row][col] = matrix[row][col];

        // solved before ?
        if(dp[row][col] != -1) return dp[row][col];

        int mn = INF;
        for(int i=-1; i<2; i++) {
            mn = min(mn, solve(row-1, col+i, matrix));
        }

        return dp[row][col] = mn + matrix[row][col];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        memset(dp, -1, sizeof(dp));

        int ans = INF;
        for(int col=0; col<n; col++) {
            ans = min(ans, solve(n-1, col, matrix));
        }

        return ans;
    }
};


//------------------------  ITERATIVE + 2-D MEMO
const int INF = INT_MAX;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int dp[n][n];

        for(int col=0; col<n; col++) dp[0][col] = matrix[0][col];

        for(int row=1; row<n; row++) {
            for(int col=0; col<n; col++) {
                int mn = INF;
                for(int dir=-1; dir<2; dir++) {
                    int new_col = col+dir;
                    if(new_col >= 0 and new_col < n)
                        mn = min(mn, dp[row-1][new_col]);
                }
                dp[row][col] = mn + matrix[row][col];
            }
        }

        int ans = INF;
        for(int col=0; col<n; col++) {
            ans = min(ans, dp[n-1][col]);
        }

        return ans;
    }
};


//------------------------  ITERATIVE + 1-D MEMO
const int INF = INT_MAX;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> old_dp(n);

        for(int col=0; col<n; col++) old_dp[col] = matrix[0][col];

        for(int row=1; row<n; row++) {
            vector<int> dp(n);
            for(int col=0; col<n; col++) {
                int mn = INF;
                for(int dir=-1; dir<2; dir++) {
                    int new_col = col+dir;
                    if(new_col >= 0 and new_col < n)
                        mn = min(mn, old_dp[new_col]);
                }
                dp[col] = mn + matrix[row][col];
            }
            old_dp.swap(dp);
        }

        int ans = INF;
        for(auto &x: old_dp) ans = min(ans, x);

        return ans;
    }
};


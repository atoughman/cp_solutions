// problem link
// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/

#include<bits/stdc++.h>
using namespace std;

///////                   DP RECURSIVE + 2-D MEMO
const int mxn = 40+3;

class Solution {
public:
    int dp[mxn][mxn];
    int solve(int l, int r, vector<int>& arr) {
        // base
        if(l == r) return dp[l][r] = 0;

        // already solved ?
        if(dp[l][r] != -1) return dp[l][r];

        int mn = INT_MAX;
        for(int k=l; k<r; k++) {
            int left_mx = 0;
            int right_mx = 0;

            for(int m=l; m<=k; m++) left_mx = max(left_mx, arr[m]);
            for(int m=k+1; m<=r; m++) right_mx = max(right_mx, arr[m]);

            mn = min(mn, solve(l,k, arr)+ (left_mx*right_mx) +solve(k+1,r, arr));
        }

        return dp[l][r] = mn;
    }

    int mctFromLeafValues(vector<int>& arr) {
        memset(dp, -1, sizeof(dp));
        return solve(0, arr.size()-1, arr);
    }
};

//                      DP ITERATIVE + 2-D MEMO

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int dp[n][n];
        for(int i=0; i<n; i++) {
            dp[i][i] = 0;
        }

        for(int c=1; c<n; c++) {
            int row = 0;
            int col = c;
            while(col < n) {
                int mn = INT_MAX;
                for(int k=row; k<col; k++) {
                    int left_mx = 0;
                    int right_mx = 0;

                    for(int m=row; m<=k; m++) left_mx = max(left_mx, arr[m]);
                    for(int m=k+1; m<=col; m++) right_mx = max(right_mx, arr[m]);

                    mn = min(mn, dp[row][k] + left_mx*right_mx + dp[k+1][col]);
                }
                dp[row][col] = mn;
                ++row;
                ++col;
            }   
        }
        
        return dp[0][n-1];
    }
};

//            GREEDY , MIN HEAP

#define pi pair<int,int>

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        int n = arr.size();
        for(int i=0; i<n; i++) {
            pq.push(make_pair(arr[i], i));
        }

        int left[n], right[n];
        for(int i=0; i<n; i++) left[i] = i-1;
        for(int i=0; i<n; i++) right[i] = i+1;

        int ans = 0;
        while(pq.size() > 1) {
            pi tmp = pq.top();
            pq.pop();
            int i = tmp.second;

            int l = left[i] >= 0 ? arr[left[i]] : INT_MAX;
            int r = right[i] < n ? arr[right[i]] : INT_MAX;

            ans += arr[i] * min(l, r);

            if(left[i] >= 0)right[left[i]] = right[i];
            if(right[i] < n)left[right[i]] = left[i];
        }

        return ans;
    }
};


//    STACK , NEXT GREATER ELEMENT VARIATION

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> st;
        int ans = 0;

        for(auto &right: arr) {
            while(!st.empty() and st.top() <= right) {
                int mid = st.top();
                st.pop();
                int left = st.empty() ? INT_MAX : st.top();
                ans += mid * min(left, right);
            }
            st.push(right);
        }

        while(st.size() > 1) {
            int mid = st.top();
            st.pop();
            int left = st.top();
            ans += mid * left;
        }

        return ans;
    }
};
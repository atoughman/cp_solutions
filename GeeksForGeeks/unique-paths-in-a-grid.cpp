// problem link
// https://practice.geeksforgeeks.org/problems/96161dfced02d544fc70c71d09b7a616fe726085/1

#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        if(grid[0][0] == 0) return 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i == 0 and j == 0) continue;
                if(grid[i][j]) {
                    long long val = 0;
                    if(i-1 >= 0) val += grid[i-1][j];
                    if(j-1 >= 0) val += grid[i][j-1];
                    grid[i][j] = val%MOD;
                }
            }
        }
        
        return grid[n-1][m-1];
    }
};
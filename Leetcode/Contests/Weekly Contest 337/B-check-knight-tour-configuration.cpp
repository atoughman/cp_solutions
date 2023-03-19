#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mx = -1;
    int n;
    
    int d8i[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int d8j[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
    
    bool inside(int i, int j) {
        return i >= 0 and j >= 0 and i < n and j < n;
    }
    
    void dfs(int i, int j, vector<vector<int>>& grid, int tar) {
        mx = max(mx, tar);
        
        for(int k=0; k<8; k++) {
            int I = i + d8i[k];
            int J = j + d8j[k];
            if(inside(I, J)) {
                if(grid[I][J] == tar + 1) {
                    dfs(I, J, grid, tar+1);
                    return;
                }
            }
        }
        
    }
    
    bool checkValidGrid(vector<vector<int>>& grid) {
        n = grid.size();
        mx = -1;
        dfs(0,0,grid, 0);
        // cout << mx << endl;
        if(mx == (n*n)-1) return true;
        return false;
    }
};
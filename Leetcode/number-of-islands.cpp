// problem link
// https://leetcode.com/problems/number-of-islands/description/

class Solution {
public:
    int n,m;
    int d4i[4] = {-1, 0, 1, 0};
    int d4j[4] = {0, 1, 0, -1};
    
    bool ok(int i, int j, vector<vector<char>>& grid, vector<vector<bool>> &vis) {
        return i>=0 and j>=0 and i<n and j<m and !vis[i][j] and grid[i][j] == '1';
    }

    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>> &vis) {
        vis[i][j] = true;

        for(int k=0; k<4; k++) {
            int I = i + d4i[k];
            int J = j + d4j[k];
            if(ok(I, J, grid, vis)) dfs(I, J, grid, vis);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(ok(i, j, grid, vis)) {
                    ++ans;
                    dfs(i, j, grid, vis);
                }
            }
        }

        return ans;
    }
};
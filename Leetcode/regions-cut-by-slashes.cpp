// problem link
// https://leetcode.com/problems/regions-cut-by-slashes/description/

class Solution {
public:
    int height, width;
    vector<string> grid;
    vector<vector<vector<bool>>> vis;

    bool is_inside_grid(int row, int col) {
        return 0 <= row && row < height && 0 <= col and col < width;
    }

    void dfs(int row, int col, int type) {
        if(!is_inside_grid(row, col) or vis[row][col][type]) return;
        vis[row][col][type] = true;

        if(type == 0) {
            dfs(row-1, col, 2);
        } else if(type == 1) {
            dfs(row, col+1, 3);
        } else if(type == 2) {
            dfs(row+1, col, 0);
        } else {
            dfs(row, col-1, 1);
        }

        if(grid[row][col] != '/') {
            dfs(row, col, (type ^ 1));
        }
        if(grid[row][col] != '\\') {
            dfs(row, col, (type ^ 3));
        }
    }


    int regionsBySlashes(vector<string>& _grid) {
        grid = _grid;
        height = (int)grid.size();
        width = (int)grid[0].size();
        vis.clear();
        vis.resize(height, vector<vector<bool>>(width, vector<bool>(4, false)));

        int regions = 0;

        for(int row=0; row<height; row++) {
            for(int col=0; col<width; col++) {
                for(int type=0; type<4; type++) {
                    if(vis[row][col][type]) continue;
                    dfs(row, col, type);
                    ++regions;
                }
            }
        }

        return regions;
    }
};
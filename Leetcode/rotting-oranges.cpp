// problem link
// https://leetcode.com/problems/rotting-oranges/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n,m;
    int d4x[4] = {0, 1, 0, -1};
    int d4y[4] = {1, 0, -1, 0};

    bool ok(int i, int j) {
        return i>=0 && j>=0 && i<n && j<m;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<array<int,3>> q;
        n = grid.size();
        m = grid[0].size();
        int time = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) q.push({i, j, 0});
            }
        }

        // bfs
        int dis = 0;
        while(!q.empty()) {
            array<int,3> ref = q.front();
            // ref has 0 -> i, 1 -> j, 2 -> time it was added

            q.pop();
            time = max(time, ref[2]);

            for(int i=0; i<4; i++) {
                int I = ref[0] + d4x[i];
                int J = ref[1] + d4y[i];
                if(ok(I,J) and grid[I][J] == 1) {
                    grid[I][J] = 2;
                    q.push({I, J, ref[2] + 1});
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }

        return time;
    }
};
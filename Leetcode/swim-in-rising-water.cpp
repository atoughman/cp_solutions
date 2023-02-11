// problem link
// https://leetcode.com/problems/swim-in-rising-water/description/

#include<bits/stdc++.h>
using namespace std;

#define ti tuple<int,int,int>
class Solution {
public:
    const int INF = INT_MAX;
    const int d4i[4] = {1, 0, -1, 0};
    const int d4j[4] = {0, 1, 0, -1};
    int n;

    bool inside(int i, int j) {
        return 0<=i and i<n and 0<=j and j<n;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int dis[n][n];
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) dis[i][j] = INF;
        dis[0][0] = grid[0][0];

        priority_queue<ti, vector<ti>, greater<ti>> q;
        q.push({dis[0][0], 0, 0});

        while(!q.empty()) {
            ti top = q.top();
            q.pop();

            int so_far = get<0>(top);
            int i = get<1>(top);
            int j = get<2>(top);

            if(i == n-1 and j == n-1) return dis[i][j];
            if(dis[i][j] < so_far) continue;

            for(int k=0; k<4; k++) {
                int I = i + d4i[k];
                int J = j + d4j[k];
                
                // validate
                if(!inside(I, J)) continue;

                // try relaxing
                int mx = max(grid[I][J], dis[i][j]);
                if(dis[I][J] > mx) {
                    dis[I][J] = mx;
                    q.push({dis[I][J], I, J});
                }
            }
        }

        // never reach here
        return dis[n-1][n-1];
    }
};
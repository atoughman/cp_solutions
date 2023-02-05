// problem link
// https://leetcode.com/problems/pacific-atlantic-water-flow/description/

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
class Solution {
public:
    int d4i[4] = {1, 0, -1, 0};
    int d4j[4] = {0, 1, 0, -1};
    int n,m;

    void dfs(int i, int j, vector<vi> &heights, vector<vi> &vis, set<vi> &water, int val) {
        // cout << i << ' ' << j << ' ' << vis[i][j] << ' ' << val << endl;
        if((vis[i][j] | val) == vis[i][j]) return;
        vis[i][j] |= val;

        for(int k=0; k<4; k++) {
            int I = i + d4i[k];
            int J = j + d4j[k];
            if(0<= I and I<n and 0<=J and J<m and heights[I][J] >= heights[i][j]) {
                water.insert({I, J});
                dfs(I, J, heights, vis, water, val);
            }
        }


    }

    vector<vector<int>> pacificAtlantic(vector<vi>& heights) {
        set<vi> atl;
        set<vi> pac;
        vector<vi> ans;
        n = heights.size();
        m = heights[0].size();
        vector<vi> vis(n, vi(m, 0)); 

        for(int j=0; j<m; j++) {
            pac.insert({0, j});
            atl.insert({n-1, j});
            dfs(0, j, heights, vis, pac, 1);
            dfs(n-1, j, heights, vis, atl, 2);
        }

        for(int i=0; i<n; i++) {
            pac.insert({i, 0});
            atl.insert({i, m-1});
            dfs(i, 0, heights, vis, pac, 1);
            dfs(i, m-1, heights, vis, atl, 2);
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                vector<int> cell = {i, j};
                if(atl.find(cell) != atl.end() and pac.find(cell) != pac.end()) {
                    ans.push_back(cell);
                }
            }
        }

        return ans;
    }
};
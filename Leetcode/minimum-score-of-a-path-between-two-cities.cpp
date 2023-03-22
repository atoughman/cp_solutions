// problem link
// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = INT_MAX;
    void dfs(int u, bool vis[], vector<pair<int,int>> adj[]) {
        vis[u] = true;

        for(auto &x: adj[u]) {
            if(!vis[x.first]) dfs(x.first, vis, adj);
            ans = min(ans, x.second);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        ans = INT_MAX;

        vector<pair<int,int>> adj[n+1];
        for(auto &x: roads) {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        
        bool vis[n+1];
        memset(vis, false, sizeof(vis));

        dfs(1, vis, adj);
        return ans;
    }
};
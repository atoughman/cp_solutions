// problem link
// https://leetcode.com/problems/is-graph-bipartite/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int u, vector<vector<int>>& graph, int col, int vis[]) {
        vis[u] = col;
        for(auto v: graph[u]) {
            if(vis[v] == -1) {
                if(dfs(v, graph, !col, vis) == false) return false;
            } else {
                if(vis[v] == col) return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        int vis[nodes+1];
        memset(vis, -1, sizeof(vis));

        for(int i=0; i<nodes; i++) {
            if(vis[i] != -1) continue;

            if(dfs(i, graph, 0, vis) == false) return false;
        }

        return true;
    }
};
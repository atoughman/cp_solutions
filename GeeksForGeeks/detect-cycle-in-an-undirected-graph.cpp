// problem link
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(int u, vector<int> adj[], bool vis[], int par) {
        vis[u] = true;
        
        for(auto &v: adj[u]) {
            if(v == par) continue;
            if(vis[v]) return true;
            if(dfs(v, adj, vis, u)) return true;
        }
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        bool vis[V];
        memset(vis, false, sizeof vis);
        
        for(int i=0; i<V; i++) {
            if(vis[i]) continue;
            if(dfs(i, adj, vis, -1)) return true;
        }
        
        return false;
        
    }
};
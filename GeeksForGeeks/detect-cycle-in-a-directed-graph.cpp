// problem link
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(int u, vector<int> adj[], int vis[]) {
        vis[u] = 1;
        
        for(auto &v: adj[u]) {
            if(vis[v] == 2) continue;
            if(vis[v] == 1) return true;
            if(dfs(v, adj, vis)) return true;
        }
        vis[u] = 2;
        
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V];
        memset(vis, 0, sizeof vis);
        
        for(int i=0; i<V; i++) {
            if(vis[i] != 0) continue;
            if(dfs(i, adj, vis)) return true;
        }
        
        return false;
    }
};
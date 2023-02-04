// problem link
// https://www.codingninjas.com/codestudio/problems/graph-valid-tree_1376618?leftPanelTab=0

#include <bits/stdc++.h> 

bool has_cycle(int u, vector<int> adj[], bool vis[], int par) {
    vis[u] = true;

    for(auto &v: adj[u]) {
        if(v == par) continue;
        if(vis[v]) return true;
        if(has_cycle(v, adj, vis, u)) return true;
    }

    return false;
}

bool checkgraph(vector<vector<int>> edges, int n, int m)
{
    vector<int> adj[n];
    for(auto &e: edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    bool vis[n];
    memset(vis, false, sizeof(vis));

    if(has_cycle(0, adj, vis, -1)) return false;

    for(int i=0; i<n; i++) if(!vis[i]) return false;
    return true;
}
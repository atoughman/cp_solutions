// problem link
// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	vector<int> order;
	
	void dfs(int u, vector<int> adj[], bool vis[], bool should_push = true) {
	    vis[u] = true;
	    
	    for(auto &v: adj[u]) {
	        if(!vis[v]) dfs(v, adj, vis, should_push);
	    }
	    if(should_push) order.push_back(u);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        int scc = 0;
        order.clear();
        vector<int> rev[V];
        
        for(int i=0; i<V; i++) {
            for(auto x: adj[i]) {
                rev[x].push_back(i);
            }
        }
        
        bool vis[V];
        memset(vis, false, sizeof(vis));
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) dfs(i, adj, vis);
        }
        
        reverse(order.begin(), order.end());
        
        memset(vis, false, sizeof(vis));
        
        for(auto &x: order) {
            if(!vis[x]) {
                ++scc;
                dfs(x, rev, vis, false);
            }
        }
        
        return scc;
    }
};
// problem link
// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int vis[26];
    vector<int> top_order;
    int comp(string a, string b) {
    	int i=0;
    	int n = min(a.size(), b.size());
    	while(i<n) {
    		if(a[i] != b[i]) return i;
    		++i;
    	}
    	return -1;
    }
    
    bool dfs(int u, vector<int> adj[]) {
    	vis[u] = 1;
    	
    	for(auto &v: adj[u]) {
    		if(vis[v] == 1) return true;
    		if(vis[v] == 0 and dfs(v, adj)) return true;
    	}
    	vis[u] = 2;
    	top_order.push_back(u);
    	return false;
    }
    
    string findOrder(string dict[], int N, int K) {
    	top_order.clear();
    	
    	int unique_edge[26][26];
    	memset(unique_edge, 0, sizeof(unique_edge));
    	memset(vis, 0, sizeof(vis));
    	
    	for(int i=0; i<N-1; i++) {
			int ind = comp(dict[i], dict[i+1]);
			if(ind != -1) unique_edge[dict[i][ind]-'a'][dict[i+1][ind]-'a'] = 1;
    	}
    	
    	vector<int> adj[26];
    	for(int i=0; i<26; i++) {
    		for(int j=0; j<26; j++) {
    			if(unique_edge[i][j]) {
    				adj[i].push_back(j);
    			}
    		}
    	}
    	
    	for(int i=0; i<K; i++) {
    		if(vis[i] == 0 and dfs(i, adj)) return "";
    	}
    	
    	reverse(top_order.begin(), top_order.end());
    	
    	string ans = "";
    	for(auto &x: top_order) {
    		ans += (x+'a');
    	}
    	
    	return ans;
    }
};
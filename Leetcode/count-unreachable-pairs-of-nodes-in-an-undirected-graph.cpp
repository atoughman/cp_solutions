// problem link
// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> adj[], bool vis[], long long &count) {
        vis[node] = true;
        count++;

        for (int next : adj[node]) {
            if (!vis[next]) {
                dfs(next, adj, vis, count);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        bool vis[n];
        memset(vis, false, sizeof(vis));

        long long edges_explored_so_far = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                long long ct = 0;
                dfs(i, adj, vis, ct);

                for (int j = 0; j < ct; j++) {
                    ans += edges_explored_so_far;
                }

                edges_explored_so_far += ct;
            }
        }

        return ans;
    }
};

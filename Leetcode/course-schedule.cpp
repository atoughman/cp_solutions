// problem link
// https://leetcode.com/problems/course-schedule/description/

class Solution {
public:
    bool has_cycle(int u, vector<int> adj[], int vis[]) {
        vis[u] = 1;

        for(auto &v: adj[u]) {
            if(vis[v] == 1) return true;
            if(!vis[v] and has_cycle(v, adj, vis)) return true;
        }
        vis[u] = 2;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        int vis[n];
        memset(vis, 0, sizeof(vis));

        for(auto &x: pre) {
            adj[x[1]].push_back(x[0]);
        }

        for(int i=0; i<n; i++) {
            if(!vis[i] and has_cycle(i, adj, vis)) return false;
        }

        return true;
    }
};
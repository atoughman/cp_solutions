// problem link
// https://leetcode.com/problems/is-graph-bipartite/description/

class Solution {
public:
    bool dfs(int u, vector<vector<int>>& graph, int col, vector<int>& vis) {
        vis[u] = col;
        bool ans = true;
        for(auto v: graph[u]) {
            if(vis[v] == -1) {
                ans &= dfs(v, graph, !col, vis);
                if(!ans) return false;
            } else {
                if(vis[v] == col) {
                    return false;
                }
            }
        }

        return ans;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> vis(nodes+1, -1);
        bool ans = true;
        for(int i=0; i<nodes; i++) {
            if(vis[i] == -1) {
                ans &= dfs(i,graph, 0, vis);
                if(ans == false) break;
            }
        }

        return ans;
    }
};
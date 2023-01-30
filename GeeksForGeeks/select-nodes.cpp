// problem link
// https://practice.geeksforgeeks.org/problems/f7bfa137576243795abb0595962d61b632bbad21/1

int ct = 0;
class Solution{
  public:
  
    bool dfs(int u, vector<int> adj[], int deg[], int par) {
        for(auto &v: adj[u]) {
            if(v == par) {
                deg[u]--;
                continue;
            }
            bool is_lit = dfs(v, adj, deg, u);
            if(is_lit) {
                deg[u]--;
            }
        }
        
        // there is no edge associated with me, what's the point of lighting up, so ...
        if(deg[u] == 0) return false;
        
        ++ct;
        return true;
        
    }
  
    int countVertex(int N, vector<vector<int>>edges){
        ct = 0;
        int deg[N+1];
        memset(deg, 0, sizeof(deg));
        
        vector<int> adj[N+1];
        for(auto &e: edges) {
            deg[e[0]]++;
            deg[e[1]]++;
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        dfs(edges[0][0], adj, deg, -1);
        
        return ct;
    }
};
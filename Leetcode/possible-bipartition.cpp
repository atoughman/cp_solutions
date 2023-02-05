// problem link
// https://leetcode.com/problems/possible-bipartition/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool can_color(int u, vector<int> adj[], int col[], int c) {
        col[u] = c;

        for(auto &v: adj[u]) {
            if(col[v] == -1) {
                if(!can_color(v, adj, col, !c)) return false;
            } else {
                if(col[v] == c) return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        int col[n+1];
        memset(col, -1, sizeof(col));

        for(auto &e: dislikes) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for(int i=1; i<=n; i++) {
            if(col[i] == -1) {
                if(!can_color(i, adj, col, 1)) return false;
            }
        }

        return true;
    }
};
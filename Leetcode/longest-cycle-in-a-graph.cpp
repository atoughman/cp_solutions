// problem link
// https://leetcode.com/problems/longest-cycle-in-a-graph/submissions/922563528/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int>& edges, vector<int>& path, vector<bool>& vis, int& ans) {
        vis[node] = true;
        path.push_back(node);

        int next = edges[node];
        while (next != -1 && !vis[next]) {
            vis[next] = true;
            path.push_back(next);
            next = edges[next];
        }

        if (next != -1) {
            auto it = find(path.begin(), path.end(), next);
            if (it != path.end()) {
                ans = max(ans, static_cast<int>(path.end() - it));
            }
        }

        path.pop_back();
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n, false);

        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> path;
                dfs(i, edges, path, vis, ans);
            }
        }

        return ans;
    }
};
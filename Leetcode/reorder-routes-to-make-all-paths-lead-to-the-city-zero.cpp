// problem link
// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n);
        for (auto& connection : connections) {
            adjList[connection[0]].push_back(connection[1]); // add directed edge from ai to bi
            adjList[connection[1]].push_back(-connection[0]); // add directed edge from bi to ai (represented by negation)
        }
        queue<int> q;
        q.push(0);

        bool vis[n];
        memset(vis, false, sizeof(vis));
        vis[0] = true;
        int route_reordered = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int neighbor : adjList[curr]) {
                if (!vis[abs(neighbor)]) { // check if neighbor is not vis yet
                    route_reordered += neighbor > 0; // increment route_reordered if the edge is reversed (neighbor > 0)
                    vis[abs(neighbor)] = true;
                    q.push(abs(neighbor));
                }
            }
        }
        
        return route_reordered;
    }
};
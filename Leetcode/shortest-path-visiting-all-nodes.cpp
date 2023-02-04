// problem link
// https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 0 or n == 1) return 0;

        int target = (1 << n) - 1;
        queue<pair<int,int>> q;
        map<pair<int,int>, bool> vis;

        for(int i=0; i<n; i++) {
            q.push({i, 1 << i});
        }

        int ans = 0;
    
        while(!q.empty()) {
            int q_size = q.size();
            ++ans;
            for(int i=0; i<q_size; i++) {
                pair<int,int> u = q.front();
                q.pop();

                for(int &v: graph[u.first]) {
                    int mask = u.second | (1 << v);
                    if(mask == target) return ans;
                    if(vis[{v, mask}]) continue;
                    vis[{v, mask}] = true;
                    q.push({v, mask});
                }
            }
        }

        // will never reach here
        return -1;
    }
};
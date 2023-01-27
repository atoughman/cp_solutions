// problem link
// https://leetcode.com/problems/network-delay-time/description/

class Solution {
public:
    const int INF = INT_MAX;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int dis[n+1];
        fill(dis, dis+n+1, INF);

        dis[k] = 0;
        for(int i=0; i<n; i++) {
            for(auto &e: times) {
                int u = e[0];
                int v = e[1];
                int w = e[2];
                dis[v] = min(dis[v], (dis[u] == INF ? INF: dis[u]+w));
            }
        }

        int mx = 0;

        for(int i=1; i<=n; i++) {
            if(dis[i] == INF) return -1;
            mx = max(mx, dis[i]);
        }

        return mx;
    }
};
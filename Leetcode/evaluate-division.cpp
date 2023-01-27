// problem link
// https://leetcode.com/problems/evaluate-division/description/

class Solution {
public:
    double dfs(string u, string target, double ans, map<string, vector<pair<string, double>>>& mp, map<string, int>& vis) {
        if(u == target) return ans;
        vis[u] = 1;
        for(auto &v: mp[u]) {
            if(vis[v.first]) continue;
            // cout << v.first << ' ' << v.second << endl;
            double res = dfs(v.first, target, (ans * v.second), mp, vis);
            if(res) return res;
        }

        return 0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> mp;
        vector<double> ans;
        map<string, int> vis;

        for(int i=0; i<values.size(); i++) {
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }

        for(int i=0; i<queries.size(); i++) {
            // not found -1
            if(mp.find(queries[i][0]) == mp.end() or mp.find(queries[i][1]) == mp.end()) ans.push_back(-1.0);
            else {
                // different
                vis.clear();
                double res = dfs(queries[i][0], queries[i][1], 1.0, mp, vis);
                ans.push_back(res ? res : -1.0);
            }
        }

        return ans;
    }
};
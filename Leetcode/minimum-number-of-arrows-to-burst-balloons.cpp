// problem link
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int,int>> v;
        for(auto &x: points) v.push_back({x[1], x[0]});
        sort(v.begin(), v.end());

        int ans = 0;
        int end = v[0].first;
        for(auto &x: v) {
            if(x.second > end) {
                ++ans;
                end = x.first;
            }
        }

        ++ans;
        
        return ans;
    }
};
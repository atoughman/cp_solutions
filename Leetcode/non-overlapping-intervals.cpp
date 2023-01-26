// problem link
// https://leetcode.com/problems/non-overlapping-intervals/description/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        for(auto x: intervals) v.push_back({x[1], x[0]});
        sort(v.begin(), v.end());

        vector<int> cur = v[0];
        int ans = 0;
        for(int i=1; i<v.size(); i++) {
            if(v[i][1] < cur[0]) ++ans;
            else cur = v[i];
        }

        return ans;
    }
};
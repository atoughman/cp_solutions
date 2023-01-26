// problem link
// https://leetcode.com/problems/merge-intervals/description/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int end = intervals[0][1];
        int start = intervals[0][0];
        vector<vector<int>> ans;
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] > end) {
                ans.push_back({start, end});
                start = intervals[i][0];
            }
            end = max(end,intervals[i][1]);
        }
        ans.push_back({start, end});
        return ans;
    }
};
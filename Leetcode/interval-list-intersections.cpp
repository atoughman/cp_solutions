// problem link
// https://leetcode.com/problems/interval-list-intersections/description/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fl, vector<vector<int>>& sl) {
        vector<vector<int>> ans;
        int fi = 0;
        int si = 0;
        int fn = fl.size();
        int sn = sl.size();

        while(fi < fn and si<sn) {
            int in_s = max(fl[fi][0], sl[si][0]);
            int in_e = min(fl[fi][1], sl[si][1]);
            
            if(in_s <= in_e) ans.push_back({in_s, in_e});
            
            if(fl[fi][1] < sl[si][1]) {
                ++fi;
            } else {
                ++si;
            }
        }

        return ans;
    }
};
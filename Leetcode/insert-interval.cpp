// problem link
// https://leetcode.com/problems/insert-interval/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ni) {
        vector<vector<int>> ans;
        int found = 0;
        int mn=0;
        int mx=0;
        for(auto &x: intervals) {
            
            if(found == 2) {
                ans.push_back(x);
            }

            if(found == 0) {
                if(ni[0] <= x[1]) {
                    mn = min(x[0], ni[0]);
                    found = 1;
                } else {
                    ans.push_back(x);
                }
            }

            if(found == 1) {
                if(ni[1] < x[0]) {
                    ans.push_back({mn, ni[1]});
                    ans.push_back(x);
                    found = 2;
                }
                else if(x[0] <= ni[1] and ni[1] <= x[1]) {
                    mx = max(x[1], ni[1]);
                    ans.push_back({mn, mx});
                    found = 2;
                }
            }
        }
        if(found == 0) ans.push_back(ni);
        if(found == 1) {
            ans.push_back({mn, ni[1]});
        }

        return ans;
    }
};
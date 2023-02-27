// problem link
// https://leetcode.com/problems/minimum-cost-for-tickets/

#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
#define all(v) v.begin(), v.end()

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<pair<int,int>> dp;
        int back[3] = {1, 7, 30};

        for(auto day: days) {
            int mn = INF;
            int cost;
            
            for(int k=0; k<3; k++) {
                auto it = upper_bound(all(dp), make_pair(day-back[k], INF));
                if(it == dp.begin()) cost = 0;
                else {
                    --it;
                    cost = (*it).second;
                }

                mn = min(mn, cost + costs[k]);
            }
            dp.push_back({day, mn});
        }
        
        return dp.back().second;
    }
};
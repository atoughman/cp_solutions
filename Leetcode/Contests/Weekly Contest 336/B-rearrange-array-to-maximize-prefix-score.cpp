#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int ct = 0;
        long long tot = 0;
        for(auto &x: nums) {
            tot += 1LL*x;
            ct += (tot>0);
        }
        
        return ct;
    }
};
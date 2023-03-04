#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        int ct = 0;
        sort(ranges.begin(), ranges.end());
        
        int end = -1;
        for(auto &x: ranges) {
            if(x[0] <= end) {
                end = max(end, x[1]);
            } else {
                ct += 1;
                end = x[1];
            }
        }
        ll ans = 1;
        for(int i=0; i<ct; i++) {
            ans <<= 1;
            ans %= MOD;
        }
        
        return ans;
    }
};
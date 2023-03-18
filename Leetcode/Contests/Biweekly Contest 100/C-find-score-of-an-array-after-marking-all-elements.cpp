#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    ll findScore(vector<int>& nums) {
        ll ans = 0;
        int n = nums.size();
        vector<pair<ll,ll>> v;
        for(ll i=0; i<n; i++) {
            v.push_back({nums[i], i});
        }
        
        map<ll,int>vis;
        
        sort(v.begin(), v.end());
        for(auto &x: v) {
            if(vis[x.second]) continue;
            int left = x.second-1;
            int right = x.second+1;
            vis[x.second] = 1;
            vis[left] = 1;
            vis[right] = 1;
            ans += x.first;
        }
        
        return ans;
    }
};
#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        ll ar[n];
        memset(ar, 0, sizeof(ar));
        map<ll, int> mp;
        mp[0] = 0;
        
        ll so_far = 0;
        ll ans = 0;
        
        for(int i=0; i<n; i++) {
            so_far ^= nums[i];
            if(mp.find(so_far) != mp.end()) {
                int ind = mp[so_far];
                ll cur = ar[ind] + 1;
                ar[i] = cur;
                ans += ar[i];
            }
            
            mp[so_far] = i;
        }
        
        return ans;
    }
};
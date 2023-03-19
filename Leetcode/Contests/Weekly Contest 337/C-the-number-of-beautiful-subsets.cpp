#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> ar;
    int k;
    
    int solve(int i, unordered_map<int,int>& vis) {
        // base
        if(i == ar.size()) {
            if(vis.size() == 0) return 0;
            else return 1;
        }
        
        // include
        int inc = 0;
        if(vis[ar[i]-k] == 0) {
            vis[ar[i]] = 1;
            inc = solve(i+1, vis);
            vis[ar[i]] = 0;
        }
        
        // exc
        int exc = solve(i+1, vis);
        
        return inc+exc;
    }
    
    int beautifulSubsets(vector<int>& nums, int _k) {
        sort(nums.begin(), nums.end());
        
        ar = nums;
        k = _k;
        
        unordered_map<int,int> vis;
        return solve(0, vis) - 1;
    }
};
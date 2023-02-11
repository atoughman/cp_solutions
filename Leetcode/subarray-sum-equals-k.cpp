// problem link
// https://leetcode.com/problems/subarray-sum-equals-k/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int ans = 0;
        int sum = 0;
        int ct = 0;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            sum += nums[i];
            if(mp.find(sum-k) != mp.end()) ct += mp[sum-k];
            mp[sum] += 1;
        }

        return ct;
    }
};

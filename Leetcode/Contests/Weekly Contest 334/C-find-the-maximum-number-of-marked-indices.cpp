#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int n = nums.size();
        int mid = n/2;
        int r = n/2;
        int ans = 0;
        
        while(r<n and l<mid) {
            if(2*nums[l] <= nums[r]) {
                ans += 2;
                ++l;
            }
            ++r;
        }
        
        return ans;
    }
};
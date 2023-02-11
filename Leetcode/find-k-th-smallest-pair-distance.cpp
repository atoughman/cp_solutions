// problem link
// 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int l = INT_MAX;
        for(int i=1; i<n; i++) {
            l = min(l, nums[i]-nums[i-1]);
        }
        int r = nums[n-1] - nums[0];
        
        // guess
        while(l <= r) {
            int m = l + (r-l)/2;
            int ct = 0;

            // check how many diffs are smaller or equal to guessed number
            int left = 0;
            int right = 1;
            while(right < n) {
                while(nums[right]-nums[left] > m) {
                    ct += right-left-1;
                    ++left;
                }
                ++right;
            }
            while(left < right) {
                ct += right-left-1;
                ++left;
            }

            if(ct < k) l = m + 1;
            else r = m - 1;
        }

        return l;
    }
};
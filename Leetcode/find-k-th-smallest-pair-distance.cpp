// problem link
// 

#include<bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

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
            for(int i=0; i<n; i++) {
                int a = nums[i];
                int low = a-m;
                int high = a+m;

                // number of elements falling in range [low, high] will give diff of smaller or equal to m
                int till_high = upper_bound(all(nums), high) - nums.begin() - 1; // -1 for not counting self
                int till_low = upper_bound(all(nums), low-1) - nums.begin();

                ct += till_high - till_low;
            }
            ct /= 2; // to handle double counting

            if(ct < k) l = m + 1;
            else r = m - 1;
        }

        return l;
    }
};
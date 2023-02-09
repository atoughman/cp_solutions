// problem link
// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int cur = 0;
        int ans = 0;

        int flip_ender[n+1];
        memset(flip_ender, 0, sizeof(flip_ender));

        for(int i=0; i<n; i++) {
            cur -= flip_ender[i];
            if(cur % 2 != 0) nums[i] = !nums[i];

            if(nums[i] == 0) {
                int r = i+k;
                if(r > n) return -1;
                
                flip_ender[r] -= 1;
                ++cur;
                ++ans;
            }
        }

        return ans;
    }
};
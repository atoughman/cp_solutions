// problem link
// https://leetcode.com/problems/number-of-zero-filled-subarrays/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long zeros = 0;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            if(nums[i] == 0) zeros += 1;
            else zeros = 0;

            if(zeros > 0) {
                ans += zeros;
            }
        }

        return ans;
    }
};
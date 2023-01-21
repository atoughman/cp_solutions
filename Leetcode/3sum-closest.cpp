// problem link
// https://leetcode.com/problems/3sum-closest/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int so_far = 0;
        int mn = INT_MAX;

        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            if(i == 0 or nums[i] != nums[i-1]) {
                int tar = target - nums[i];
                int l = i+1;
                int r = nums.size() - 1;
                while(l<r) {
                    int sum = nums[l] + nums[r];
                    if(sum == tar) return target;
                    int diff = abs(tar - sum);
                    if(mn > diff) {
                        mn = diff;
                        so_far = nums[i] + sum;
                    }
                    if(sum < tar) ++l;
                    else --r;
                }
            }
        }

        return so_far;
    }
};
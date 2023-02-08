// problem link
// https://leetcode.com/problems/jump-game-ii/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {

        int cur_far = 0;
        int cur_end = 0;
        int ans = 0;

        for(int i=0; i<nums.size()-1; i++) {
            cur_far = max(cur_far, nums[i]+i);
            if(i == cur_end) {
                ++ans;
                cur_end = cur_far;
            }
        }

        return ans;
    }
};
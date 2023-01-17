// problem link
// https://leetcode.com/problems/permutations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generate_perm(vector<int> &nums, vector<vector<int>> &ans, int ind = 0) {
        if(ind == nums.size()) ans.push_back(nums);
        else {
            for(int i=ind; i<nums.size(); i++) {
                swap(nums[i], nums[ind]);
                generate_perm(nums, ans, ind + 1);
                swap(nums[i], nums[ind]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        generate_perm(nums, ans);
        return ans;
    }
};
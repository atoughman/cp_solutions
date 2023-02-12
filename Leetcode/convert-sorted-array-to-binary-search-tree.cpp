// problem link
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* build(vector<int>& nums, int l, int r) {
        if(l>r) return NULL;
        int mid = l + (r-l)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = build(nums, l, mid-1);
        node->right = build(nums, mid+1, r);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }
};
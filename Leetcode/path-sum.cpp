// problem link
// https://leetcode.com/problems/path-sum/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        if(root->left == NULL and root->right == NULL and root->val == targetSum) return true;
        targetSum -= root->val;
        return hasPathSum(root->left, targetSum) or hasPathSum(root->right, targetSum);
    }
};
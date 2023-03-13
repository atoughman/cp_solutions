// problem link
// https://leetcode.com/problems/symmetric-tree/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(TreeNode* left, TreeNode* right) {
        if(left == NULL and right == NULL) return true;
        if(left == NULL or right == NULL) return false;
        if(left->val != right->val) return false;

        return dfs(left->left, right->right) and dfs(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }
};
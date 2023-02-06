// problem link
// https://leetcode.com/problems/binary-tree-pruning/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) return NULL;

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if(root->left == NULL and root->right == NULL and root->val == 0) return NULL;
        
        return root;
    }
};
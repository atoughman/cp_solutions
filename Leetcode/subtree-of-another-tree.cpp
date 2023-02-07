// problem link
// https://leetcode.com/problems/subtree-of-another-tree/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(TreeNode* a, TreeNode* b) {
        if(a == NULL and b == NULL) return true;
        if(a == NULL || b == NULL) return false;
        if(a->val != b->val) return false;
        return check(a->left, b->left) and check(a->right, b->right);
        
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;
        if(root->val == subRoot->val) {
            if(check(root, subRoot)) return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
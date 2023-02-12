// problem link
// https://leetcode.com/problems/search-in-a-binary-search-tree/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL or root->val == val) return root;

        if(root->val > val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
    }
};
// problem link
// https://leetcode.com/problems/validate-binary-search-tree/description/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    bool isValidBST(TreeNode* root, ll left = -(1LL<<32), ll right = 1LL<<32) {
        if(root->val <= left or right <= root->val) return false;
        if(root->left != NULL) {
            if(!isValidBST(root->left, left, root->val)) return false;
        }
        if(root->right != NULL) {
            if(!isValidBST(root->right, root->val, right)) return false;
        }
        return true;
    }
};
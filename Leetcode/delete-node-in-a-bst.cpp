// problem link
// https://leetcode.com/problems/delete-node-in-a-bst/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key) {
            TreeNode* right = root->right;
            TreeNode* left = root->left;
            delete root;
            
            if(left == NULL) {
                return right;
            }
            if(right == NULL) {
                return left;
            }

            TreeNode* right_child_of_left = left->right;
            left->right = right;

            TreeNode* left_most = right;
            while(left_most->left != NULL) left_most = left_most->left;
            left_most->left = right_child_of_left;

            return left;
        }

        if(root->val > key) root->left = deleteNode(root->left, key);
        else root->right = deleteNode(root->right, key);

        return root;
    }
};
// problem link
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

class Solution {
public:
    int cur = 0;

    TreeNode* build(int left, int right, vi& inorder, vi& postorder) {
        if(left > right) return NULL;
        int hinge_point = -1;
        for(int i=left; i<=right; i++) {
            if(inorder[i] == postorder[cur]) {
                hinge_point = i;
                break;
            }
        }

        TreeNode* node = new TreeNode(postorder[cur]);
        cur -= 1;

        node->right = build(hinge_point + 1, right, inorder, postorder);
        node->left = build(left, hinge_point - 1, inorder, postorder);
        return node;
    }

    TreeNode* buildTree(vi& inorder, vi& postorder) {
        cur = inorder.size() - 1;
        return build(0, inorder.size()-1, inorder, postorder);
    }
};
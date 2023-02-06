// problem link
// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> ans;
    void dfs(TreeNode* u) {
        if(u == NULL) return;
        dfs(u->left);
        ans.push_back(u->val);
        dfs(u->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        ans.clear();
        dfs(root);
        return ans;
    }
};
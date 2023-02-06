// problem link
// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void dfs(TreeNode* u, int level) {
        if(u == NULL) return;
        if(ans.size() < level) {
            ans.push_back({u->val});
        } else {
            ans[level-1].push_back(u->val);
        }
        dfs(u->left, level+1);
        dfs(u->right, level+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        ans.clear();
        dfs(root, 1);
        return ans;
    }
};
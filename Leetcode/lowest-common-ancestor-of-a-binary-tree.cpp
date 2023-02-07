// problem link
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* lca;
    int dfs(TreeNode* u, TreeNode* p, TreeNode* q) {
        if(u == NULL) return 0;
        if(lca != NULL) return 0;

        int ans = 0;
        ans |= dfs(u->left, p, q);
        ans |= dfs(u->right, p, q);
        if(u == p) ans |= 1;
        if(u == q) ans |= 2;
        if(lca == NULL and ans == 3) lca = u;
        return ans;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca = NULL;
        dfs(root, p, q);
        return lca;
    }
};
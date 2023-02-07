// problem link
// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int so_far;

    int dfs(TreeNode* u) {
        if(u == NULL) return 0;

        int l = max(0, dfs(u->left));
        int r = max(0, dfs(u->right));
        
        so_far = max(so_far, l+r+(u->val));
        
        return max(l, r) + u->val;
    }

    int maxPathSum(TreeNode* root) {
        so_far = -2000;
        dfs(root);
        return so_far;
    }
};
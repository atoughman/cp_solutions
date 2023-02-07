// problem link
// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* u, int val) {
        if(u == NULL) return;
        int so_far = val*10 + u->val;
        if(u->left == NULL and u->right == NULL) {
            ans += so_far;
            return;
        }

        dfs(u->left, so_far);
        dfs(u->right, so_far);

    }
    int sumNumbers(TreeNode* root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};
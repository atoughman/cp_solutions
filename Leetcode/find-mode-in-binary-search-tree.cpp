// problem link
// https://leetcode.com/problems/find-mode-in-binary-search-tree/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mx = 0;
    int ct = 0;
    bool mode_freq_found;
    vector<int> ans;
    TreeNode* prev;

    void in_order(TreeNode* u) {
        if(u == NULL) return;

        in_order(u->left);

        if(prev != NULL and prev->val == u->val) ++ct;
        else ct = 1;
        prev = u;
        
        if(mode_freq_found) {
            if(mx == ct) ans.push_back(u->val);
        }
        else mx = max(mx, ct);

        in_order(u->right);
    }

    vector<int> findMode(TreeNode* root) {
        prev = NULL;
        ans.clear();
        mx = 0;
        ct = 0;
        mode_freq_found = false;

        in_order(root);

        ct = 0;
        mode_freq_found = true; // mode is found, now build answer
        in_order(root);

        return ans;
    }
};
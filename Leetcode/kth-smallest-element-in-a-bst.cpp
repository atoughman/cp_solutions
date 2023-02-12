// problem link
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

#include<bits/stdc++.h>
using namespace std;

// -------------------------  recursive

class Solution {
public:
    int so_far = 0;
    int ans = 0;
    void search(TreeNode* u, int k) {
        if(u == NULL) return;

        // left
        search(u->left, k);
        if(so_far == k) return;

        // self
        so_far += 1; 
        if(so_far == k) {
            ans = u->val;
            return;
        }

        // right
        search(u->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        so_far = 0;
        search(root, k);
        return ans;
    }
};
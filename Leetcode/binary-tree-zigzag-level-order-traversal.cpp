// problem link
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        bool rev = true;

        q.push(root);

        while(!q.empty()) {
            int sz = q.size();
            rev = !rev;
            vector<int> res;
            for(int i=0; i<sz; i++) {
                TreeNode* u = q.front();
                q.pop();
                if(u == NULL) continue;

                res.push_back(u->val);
                q.push(u->left);
                q.push(u->right);
            }
            if(rev) reverse(res.begin(), res.end());
            if(!res.empty()) ans.push_back(res);
        }

        return ans;
    }
};
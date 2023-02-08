// problem link
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

#include<bits/stdc++.h>
using namespace std;

// --------------  DIVIDE AND CONQUER ( this is better )

class Solution {
public:
    unordered_map<int, int> mp;
    int pi = 0;

    TreeNode* build(vector<int>& preorder, int left, int right) {
        if(left > right) return NULL;
        int val = preorder[pi];
        pi += 1;
        TreeNode* node = new TreeNode(val);

        node->left = build(preorder, left, mp[val] - 1);
        node->right = build(preorder, mp[val] + 1, right);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pi = 0;
        mp.clear();
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1);
    }
};

// ----------------  DFS

class Solution {
public:
    int prei, ini, n;
    vector<int> pre, in;
    map<int,int> vis;

    TreeNode* helper() {
        if(prei>=n or ini >= n or vis[in[ini]]) return NULL;
        TreeNode* node = new TreeNode(pre[prei]);
        vis[pre[prei]] = 1;
        ++prei;

        node->left = helper();
        ++ini;
        node->right = helper();

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        in = inorder;
        vis.clear();
        prei = 0;
        ini = 0;
        n = pre.size();
        
        return helper();
    }
};
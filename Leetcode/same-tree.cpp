// problem link
// https://leetcode.com/problems/same-tree/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL and q != NULL) return false;
        if(p != NULL and q == NULL) return false;
        if(p == NULL and q == NULL) return true;

        bool is_same;
        is_same = isSameTree(p->left, q->left);
        if(!is_same) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->right, q->right);
    }
};
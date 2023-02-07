// problem link
// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};
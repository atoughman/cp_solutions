// problem link
// https://leetcode.com/problems/binary-tree-cameras/description/

#include<bits/stdc++.h>
using namespace std;

enum Camera {
    HAS_CAMERA,
    COVERED,
    PLEASE_COVER
};

class Solution {
public:
    int ans = 0;

    Camera cover(TreeNode* u) {
        if(u == NULL) return COVERED;

        Camera left = cover(u->left);
        Camera right = cover(u->right);

        if(left == PLEASE_COVER or right == PLEASE_COVER) {
            ++ans;
            return HAS_CAMERA;
        }

        if(left == HAS_CAMERA or right == HAS_CAMERA) {
            return COVERED;
        }

        return PLEASE_COVER;

    }
    
    int minCameraCover(TreeNode* root) {
        ans = 0;
        Camera node = cover(root);
        if(node == PLEASE_COVER) ++ans;
        return ans;
    }
};
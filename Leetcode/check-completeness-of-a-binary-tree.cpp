// problem link
// 

#include<bits/stdc++.h>
using namespace std;

enum bt_state {
    COMPLETE_BT,
    INCOMPLETE_BT
};

class Solution {
public:
    int lowest_level = -1;
    bool gap = false;

    bt_state dfs(TreeNode* u, int level) {
        if(u == NULL) {
            if(lowest_level == -1) lowest_level = level;
            else if(level != lowest_level) {
                if(level == lowest_level-1) {
                    gap = true;
                } else return INCOMPLETE_BT;
            }
            return COMPLETE_BT;
        } else {
            if(level == lowest_level-1) { // found gap in last level
                if(gap) return INCOMPLETE_BT;
            }
        }

        if(dfs(u->left, level + 1) == INCOMPLETE_BT) return INCOMPLETE_BT;
        return dfs(u->right, level + 1);
    }

    bool isCompleteTree(TreeNode* root) {
        return dfs(root, 0) == COMPLETE_BT ? true : false;
    }
};
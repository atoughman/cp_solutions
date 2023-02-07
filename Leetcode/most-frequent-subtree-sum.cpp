// problem link
// https://leetcode.com/problems/most-frequent-subtree-sum/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int,int> mp;
    int dfs(TreeNode* u) {
        if(u == NULL) return 0;
        int sum = 0;
        sum += dfs(u->left);
        sum += dfs(u->right);
        sum += u->val;
        mp[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        mp.clear();
        dfs(root);
        int mx = 0;
        for(auto x: mp) {
            mx = max(mx, x.second);
        }
        for(auto x: mp) {
            if(x.second == mx) ans.push_back(x.first);
        }
        return ans;
    }
};
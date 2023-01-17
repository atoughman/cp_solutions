// problem link
// https://leetcode.com/problems/generate-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gen(vector<string> &ans, string &so_far, int op, int cl) {
        if(op == 0 and cl == 0) {
            ans.push_back(so_far);
            return;
        }
        if(op > 0) { // possible to add '('
            so_far.push_back('(');
            gen(ans, so_far, op-1, cl);
            so_far.pop_back();
        }

        if(cl > op) { // possible to add ')'
            so_far.push_back(')');
            gen(ans, so_far, op, cl-1);
            so_far.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string so_far = "";
        gen(ans, so_far, n, n);

        return ans;
    }
};
// problem link
// https://leetcode.com/problems/pascals-triangle/description/

#include <bits/stdc++.h>
using namespace std;

// recursive
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        else {
            vector<vector<int>> ans = generate(numRows - 1);
            vector<int> last = ans.back();
            vector<int> cur = {1};
            for(int i=1; i<last.size(); i++) {
                cur.push_back(last[i] + last[i-1]);
            }
            cur.push_back(1);
            ans.push_back(cur);
            return ans;
        }

    }
};

// iterative
class Solution {
public:

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp = {1};
        ans.push_back(temp);
        for(int i=2; i<=numRows; i++) {
            temp.push_back(0);

            for(int j=temp.size()-1; j>0; j--) {
                temp[j] = temp[j] + temp[j-1];
            }

            // push
            ans.push_back(temp);
        }
        return ans;
    }
};
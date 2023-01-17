// problem link
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        else if(digits.size() == 1) {
            vector<vector<string>> v;
            v.push_back({"a","b","c"});
            v.push_back({"d","e","f"});
            v.push_back({"g","h","i"});
            v.push_back({"j","k","l"});
            v.push_back({"m","n","o"});
            v.push_back({"p","q","r", "s"});
            v.push_back({"t","u","v"});
            v.push_back({"w","x","y", "z"});

            return v[digits[0]-'2'];
        }
        else {
            vector<string> ans;
            vector<string> a = letterCombinations(digits.substr(0, 1));
            vector<string> b = letterCombinations(digits.substr(1, digits.size()-1));

            for(auto x: a) {
                for(auto y: b) {
                    ans.push_back(x+y);
                }
            }
            
            return ans;
        }
    }
};
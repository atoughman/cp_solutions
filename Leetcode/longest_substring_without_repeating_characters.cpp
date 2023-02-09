// problem link
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> next;

        int l = 0;
        int r = 0;
        int n = s.size();
        int ans = 0;

        while(r<n) {
            if(next[s[r]] > 0) {
                l = max(l, next[s[r]]);
            }
            ans = max(ans, r-l+1);
            next[s[r]] = r+1;
            ++r;
        }  

        return ans;
    }
};
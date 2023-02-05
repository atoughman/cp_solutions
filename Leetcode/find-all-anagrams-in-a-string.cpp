// problem link
// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int freq[26]={0};
        int target[26]={0};
        for(auto &x: p) {
            target[x-'a']++;
        }

        int ct = 0;
        for(auto x: target) if(x == 0) ++ct;

        int len = p.size();
        for(int i=0; i<s.size(); i++) {
            freq[s[i]-'a']++;
            if(freq[s[i]-'a'] == target[s[i]-'a']) ++ct;

            if(ct == 26) {
                ans.push_back(i+1-len);
            }

            if(i>=len-1) {
                if(freq[s[i+1-len]-'a'] == target[s[i+1-len]-'a']) --ct;
                freq[s[i+1-len]-'a']--;
            }
        }

        return ans;
    }
};